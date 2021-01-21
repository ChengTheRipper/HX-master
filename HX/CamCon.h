#pragma once

#include "pch.h"
#include "opencv_include.h"
#include "CPublic.h"

using namespace std;
using namespace cv;


//��ʼ��PitureControl�ؼ�
void PicConInit(HWND hWnd, int IDD, const char* windowname);



class CSampleDeviceOfflineEventHandler : public IDeviceOfflineEventHandler
{
public:

	void DoOnDeviceOfflineEvent(void* pUserParam);
};

//�û��̳����Ը����¼�������

class CSampleFeatureEventHandler : public IFeatureEventHandler
{
public:
	void DoOnFeatureEvent(const GxIAPICPP::gxstring& strFeatureName, void* pUserParam)
	{
		cout << "�յ��ع�����¼�!" << endl;
	}
};

//�û��̳вɼ��¼�������
class CSampleCaptureEventHandler : public ICaptureEventHandler
{
public:

	void DoOnImageCaptured(CImageDataPointer& objImageDataPointer, void* pUserParam);

};
class SingleCam;


/// <summary>
/// Cam���߱�������������ϸ�λ���ܣ��Ѹ�λ����������
/// �����������
/// </summary>
class CamCon //Cam����
{
public:

	enum {
		LEFT,
		RIGHT,
	};


	CamCon() { CamInit(); };
	~CamCon() { CamUnInit(); };
	int init_all_cam(vector<shared_ptr<SingleCam>>& cam_vec);
	//��ʼ������
	int CamInit();
	int CamUnInit();

	//ɨ���������
	size_t ScanCam();
	//��λ�������
	void SoftResetAllCam();

	static shared_ptr<SingleCam> LEFT_CAM;
	static shared_ptr<SingleCam> RIGHT_CAM;

public:

private:
	//��ֹ����
	CamCon(const CamCon&);
	CamCon operator=(const CamCon&);

	gxdeviceinfo_vector vectorDeviceInfo;//�������߰����������Ϣ

	vector<gxstring> macAddrList;

};
class SingleCam//�������
{
	friend class CvisonDlg;
	friend class CSampleCaptureEventHandler;
	friend class CamCon;
public:

	SingleCam(gxstring m_serialNum, const char* windowname, const cv::Rect& roi);
	~SingleCam();
public:

	//�������Ϊ����ģʽ
	void SetAcqusition_Continuous();
	//�������Ϊ����ģʽ
	void SetAcqusition_SoftwareTrigger();


	void Record_start();
	void Record_stop();
	cv::Rect ROI;

	inline bool& IsOffline()
	{
		return m_bIsOffline;
	}

	gxstring GetSN() const
	{
		return serialNum;
	}
	string GetShowWindow() const
	{
		return showWindowName;
	}
	Mat GetSrc() const
	{
		return src;
	}
	double GetShutterTime() const
	{
		return m_dcurCamShutterTime;
	}
public:
	//��־λ
	bool m_bIsOffline;     //�Ƿ�����
	bool m_bIsSnap;        //�Ƿ��ڲɼ�
	bool m_bIsOpened;      //�Ƿ��Ѿ���
	bool m_bTriggerMode;   //�Ƿ�֧�ִ���
	bool m_bTriggerSource; //�Ƿ�֧��ѡ�񴥷�Դ
	bool m_frame_ready_;//֡�������
	//�豸�����������������ֵ���ع�ʱ�䷶Χ��
	double m_dShutterValueMax;//����
	double m_dShutterValueMin;
	double m_dGainValueMax;//����
	double m_dGainValueMin;

	CGXFeatureControlPointer   ObjFeatureControlPtr;//�豸���Կ�����
	CGXFeatureControlPointer   ObjStreamFeatureControlPtr;//�������������
private:
	//��ֹ�������
	SingleCam(const SingleCam&);
	const SingleCam& operator=(const SingleCam&);
	//���ߴ���
	void __ProcessOffline();
	//��������
	void __Recovery();
	//��ʼ���������
	void __InitParam();
	//����Handler
	IDeviceOfflineEventHandler* pDeviceOfflineEventHandler;///<�����¼��ص�����
	IFeatureEventHandler* pFeatureEventHandler;///<Զ���豸�¼��ص�����
	ICaptureEventHandler* pCaptureEventHandler;///<�ɼ��ص�����


	CGXDevicePointer ObjDevicePtr;//�豸ָ��
	CGXStreamPointer ObjStreamPtr;//����

	GX_DEVICE_OFFLINE_CALLBACK_HANDLE hDeviceOffline; //���߻ص����


	//�����������ʱ��������
	double m_dcurCamGain;       //�����ǰ����
	double m_dcurCamShutterTime;//�����ǰ����ʱ��


	//���к�
	gxstring serialNum;
	//������ʾ��������
	string showWindowName;

	//Դͼ
	Mat src;
	//���к��ԭͼ��
	Mat croppedSrc;
	//��С���ԭͼ
	Mat resizedSrc;
	//��С��Ĳ���ͼ
	Mat resizedCropped;

};



//֮��˫�����ĵĴ���
int StartCam(std::shared_ptr<SingleCam> p);
int StopCam(std::shared_ptr<SingleCam> p);

static CamCon& CAMVEC()
{
	static CamCon c1;
	return c1;
}
//single_cam vector
static vector<shared_ptr<SingleCam>>& SCV()
{
	static vector<shared_ptr<SingleCam>> c1;
	return c1;
}



