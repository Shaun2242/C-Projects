#include "CCImage.h"
#include "UJEdgeFilter.h"
#include "UJBlurFilter.h"

int main(int argc, char** argv)
{
    // Command Line Arguments
    if(argc != 4){
        cerr << "ERROR: Usage-> " << argv[0] << " TYPE OF FILTER, NUMBER OF TIMES, PPM FILE NAME INCLUDING EXTENSION" << endl;
        exit(ERROR_INVALID_CMD_ARGS);
    }

    char chFilter = argv[1][0];                 // Character Value
    int intNumPasses = covStrToInt(argv[2]);    // Integer Value
    string strFileName = argv[3];               // String / char* Value

    // Read the Image (Creative Commons Licensed Image)
    //CCImage objImage = loadPPMImage("Broken_Hill_Wall_Mural.ppm");
    CCImage objImage = loadPPMImage(strFileName);

    /**
	** Menu System
	** Remove Comments once you create classes
	**/

    switch(tolower(chFilter)){
    case 'b':   // Blur Kernel
        {
			/**
			** TODO: UnComment this section once UJBlurFilter class is complete
			**/
            // Initialize Filter
            UJBlurFilter objFilteredImage_1;
            // Call Filter on CCImage
            objFilteredImage_1.applyFilter(objImage, intNumPasses);
            break;
        }
    case 'e':   // Edge Detection Kernel
        {
			/**
			** TODO: UnComment this section once UJEdgeFilter class is complete
			**/
            // Initialize Filter
             UJEdgeFilter objFilteredImage_2;
            // Call Filter on CCImage
             objFilteredImage_2.applyFilter(objImage, intNumPasses);
            break;
        }
    default:
        cerr << "Invalid filter type " << chFilter << endl;
        exit(ERROR_INVALID_FILTER_TYPE);
    }

    //Generate new PPM Image
    cout << objImage.toPPM();

    return SUCCESS;
}
