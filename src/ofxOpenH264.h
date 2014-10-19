#pragma once
#include "codec_api.h"
#include "codec_app_def.h"
#include "codec_def.h"
#include "ofPixels.h"



class ofxOpenH264
{
public:
	ofxOpenH264(void);
	~ofxOpenH264(void);

	bool openEncodeSession(int width, int height, int bitrate, float framerateMax, bool bScreenContent = true);
	void encodeFrame(const ofPixels & pixels);
	void closeEncodeSession();

private:
	bool bSessionOpen;
	ISVCEncoder * openH264Encoder;
	SEncParamBase encoderParameters;
	
	unsigned char * yuvPlanes;
};

