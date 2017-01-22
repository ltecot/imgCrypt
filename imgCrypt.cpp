#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
using namespace cv;

static void help()
{
    cerr
        << "\n--------------------------------------------------------------------------" << endl
        << "./imgCrypt D imgFile [M]" << endl
        << "./imgCrypt E imgFile textFile [M]" << endl
        << "Put D as first arg for decrypt, E for encrypt" << endl
        << "Put M as last arg if you want a datamoshed image." << endl
        << "--------------------------------------------------------------------------"   << endl
        << endl;
}

Mat& Encrypt(Mat& I, ifstream& file);
void Decrypt(Mat& I);
bool tock;
unsigned char whole = 255;
unsigned char r = whole & 0xF;
unsigned char l = whole & 0xF0;

int main( int argc, char* argv[])
{
    help();

    tock = false;

    srand (time(NULL));

    if(!strcmp(argv[1], "D"))
    {
        if (argc < 3)
        {
            cerr << "Not enough parameters." << endl;
            return -1;
        }

        Mat I;
        I = imread(argv[2], CV_LOAD_IMAGE_COLOR);

        if (!I.data)
        {
            cerr << "The image" << argv[2] << " could not be loaded." << endl;
            return -1;
        }

        Decrypt(I);

    }
    else if(!strcmp(argv[1], "E"))
    {
        if (argc < 4)
        {   
            cerr << "Not enough parameters." << endl;
            return -1;
        }

        Mat I, J;
        I = imread(argv[2], CV_LOAD_IMAGE_COLOR);

        if (!I.data)
        {
            cerr << "The image" << argv[2] << " could not be loaded." << endl;
            return -1;
        }

        ifstream file(argv[3]);
        if (!file.is_open())
        {
            cerr << "Unable to open file";
            return -1;
        }

        J = Encrypt(I, file);
        file.close();
        imwrite( argv[2], J );

    }
    else
    {
        cerr << "Give D or E for first arg." << endl;
    }

    return 0;
}

Mat& Encrypt(Mat& I, ifstream& file)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    char c;
    bool stop = false;
    bool stopN = false;
    for( i = 0; i < nRows && !stop; ++i)
    {
        p = I.ptr<uchar>(i);
        for ( j = 0; j < nCols && !stop; ++j)
        {
            if(stopN)
                stop = true;

            if(!tock)
            {
                file.get(c);
                if(!c)
                    stopN = true;
            }
            else 
                c = c >> 4;

            p[j] = (l & p[j]) | (r & c);

            tock = !tock;
            
        }
    }
    return I;
}

void Decrypt(Mat& I)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    char c;
    bool stop = false;
    for( i = 0; i < nRows && !stop; ++i)
    {
        p = I.ptr<uchar>(i);
        for ( j = 0; j < nCols && !stop; ++j)
        {
            char info = r & p[j];
            if(!tock) 
                c = info;
            else 
            {
                c = info << 4 | c;
                cout << c;
                if(!c)
                    stop = true;
                c = 0;
            }
            tock = !tock;
        }
    }
}