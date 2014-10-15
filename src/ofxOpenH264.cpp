#include "ofxOpenH264.h"



ofxOpenH264::ofxOpenH264(void) :
	openH264Encoder(NULL),
	bSessionOpen(false)
{
	memset(&encoderParameters, 0, sizeof(SEncParamBase));
}


bool ofxOpenH264::openEncodeSession(int width, int height, int bitrate, float framerateMax, bool bScreenContent)
{
	int encoderSetupFailure = WelsCreateSVCEncoder(&openH264Encoder);
	if( encoderSetupFailure  || openH264Encoder == NULL)
		bSessionOpen = false;

	encoderParameters.iUsageType = bScreenContent ? EUsageType::SCREEN_CONTENT_REAL_TIME : EUsageType::CAMERA_VIDEO_REAL_TIME;
	encoderParameters.iPicWidth = width;
	encoderParameters.iPicHeight = height;
	encoderParameters.iTargetBitrate = bitrate;
	encoderParameters.fMaxFrameRate = framerateMax;
	encoderParameters.iRCMode = RC_MODES::RC_QUALITY_MODE;
	bSessionOpen = openH264Encoder->Initialize(&encoderParameters) == 0;

	return bSessionOpen;
}


void ofxOpenH264::encodeFrame(const ofPixels & pixels)
{

}


void ofxOpenH264::closeEncodeSession()
{

}


ofxOpenH264::~ofxOpenH264(void)
{
}

