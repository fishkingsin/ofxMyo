#pragma once

#include "../ofxMyoDefines.h"
#include <myo.hpp>

class MyoDataCollector : public myo::DeviceListener 
{

public:
    MyoDataCollector();
    void onUnpair(myo::Myo* myo, uint64_t timestamp);
    void onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& quat);
    void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);
    void onArmSync(myo::Myo* myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection);
    void onArmUnsync(myo::Myo* myo, uint64_t timestamp);
    void onUnlock(myo::Myo* myo, uint64_t timestamp);
    void onLock(myo::Myo* myo, uint64_t timestamp);
    void print();
    MyoFrameOrientationData getCurrFrameOrientionData() const;
    MyoFramePoseData getCurrFramePoseData() const;
private:

	MyoFrameOrientationData m_orientation_data;
	MyoFramePoseData m_pose_data;
    
    // These values are set by onArmSync() and onArmUnsync() above.
    bool onArm;
    myo::Arm whichArm;
    
    // This is set by onUnlocked() and onLocked() above.
    bool isUnlocked;
    
    // These values are set by onOrientationData() and onPose() above.
    int roll_w, pitch_w, yaw_w;
    myo::Pose currentPose;


};