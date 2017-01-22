#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;
using namespace cv;

static void help()
{
    cerr
        << "\n--------------------------------------------------------------------------" << endl
        << "./imgCrypt D imgFile" << endl
        << "./imgCrypt E imgFile textFile [destImg]" << endl
        << "Put D as first arg for decrypt, E for encrypt." << endl
        << "Does not support lossy format output. Make sure to give a lossless format for encrypt output." << endl
        << "--------------------------------------------------------------------------"   << endl
        << endl;
}

Mat& Encrypt(Mat& I, ifstream& file);
void Decrypt(Mat& I);
bool tock;
unsigned char whole = 255;
unsigned char r = whole & 0xF;
unsigned char l = whole & 0xF0;

string type2str(int type) {
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}

int main( int argc, char* argv[])
{
    help();

    tock = false;

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

        ifstream file(argv[3], std::ios::binary);
        if (!file.is_open())
        {
            cerr << "Unable to open file";
            return -1;
        }

        J = Encrypt(I, file);
        file.close();
        if (argc >= 5)
            imwrite( argv[4], J );
        else
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
                if(file.eof())
                    stopN = true;
            }
            else 
                c = c >> 4;

            //cout << p[j] << endl;
            p[j] = (l & p[j]) | (r & c);
            //cout << p[j] << endl << endl;
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
                if(c == -1)
                    stop = true;
                c = 0;
            }
            tock = !tock;
        }
    }
}