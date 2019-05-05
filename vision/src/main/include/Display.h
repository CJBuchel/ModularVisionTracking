#include "CJlib/cj.h"

Display::Display(Process &process) : _process(process), _capture(process.GetCapture()) {}

void Display::Init() {
  
  _videoMode = _capture.GetVideoMode();

  // Set up output
  _outputCam0 = frc::CameraServer::GetInstance()->PutVideo("USB CameraTape", _videoMode.width, _videoMode.height);
  _outputCam1 = frc::CameraServer::GetInstance()->PutVideo("USB CameraGamePeice", _videoMode.width, _videoMode.height);
}


void Display::Periodic() {
  // Capture &capture = _process.GetCapture();
  _process.CopyProcessedTrack(_imgProcessedTrack);
  _process.CopyProcessedTrack(_imgProcessedTrackHatch);
  // _capture.CopyCaptureMat(_imgProcessedTrack);
  // _process.CopyProcessedThresh(_imgProcessedThresh);
  // _capture.CopyCaptureMat(_imgOriginal);
  if (_capture.IsValidFrameThresh() && _capture.IsValidFrameTrack()) {
    if (_process.GetValidThresh() && _process.GetValidTrack()) {
#ifdef __DESKTOP__
      //imshow("OutputOrigin", _imgOriginal);
      if (_imgProcessedTrack.rows > 0) {
        imshow(_process.GetProcessType(), _imgProcessedTrack);
      }
        // imshow(_process.GetProcessType(), _imgProcessedThresh);
        // imshow("OutputBallThresh", _imgBallThresh);
        // imshow("OutputBallTrack", _imgBallTrack);
        // cv::waitKey(500 / 30);
        // imshow("OutputHatchThresh", _imgHatchThresh);
        // imshow("OutputHatchTrack", _imgHatchTrack);
        // imshow("OutputTapeThresh", _imgTapeThresh);
        // imshow("OutputTapeTrack", _imgTapeTrack);
        
        cv::waitKey(1000 / 30);
    
#else
        // Grab a frame. If it's not an error (!= 0), convert it to grayscale and send it to the dashboard.
        _outputCam0.PutFrame(_imgProcessedTrack);
        _outputCam1.PutFrame(_imgProcessedTrackHatch);
        //_ouput.PutFrame(_capture);
#endif
		std::cout << "Origin Image Processed" << std::endl;
    // other output if needed
    }
  }
  else {
    std::cout << "Origin Image is Not Available" << std::endl;
  }
  std::this_thread::sleep_for(std::chrono::duration<double>(5.0 / 90));
}

