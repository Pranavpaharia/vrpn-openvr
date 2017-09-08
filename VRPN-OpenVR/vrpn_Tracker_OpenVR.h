#pragma once

#include <string>
#include <openvr.h>
#include <vrpn_Tracker.h>
#include <quat.h>

class vrpn_Tracker_OpenVR :
	public vrpn_Tracker
{
public:
	vrpn_Tracker_OpenVR(const std::string& name, vrpn_Connection* connection, vr::IVRSystem * vr);
	void mainloop() override;
	void updateTracking(vr::TrackedDevicePose_t *pose);
protected:
	vr::IVRSystem * vr;
private:
	std::string name;
	q_matrix_type matrix;
	static void ConvertSteamVRMatrixToQMatrix(const vr::HmdMatrix34_t &matPose, q_matrix_type &matrix);
};

