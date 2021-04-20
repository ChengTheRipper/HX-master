#pragma once

#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define _F_LOGIN "./login.ini"
#define _F_STOCK "./stock.txt"

using namespace std;

struct msg
{
	CString backboard; //�����ͺ�
	double x_floor; //x����
	double x_ceil; //x����
	double y_floor; //x����
	double y_ceil; //x����
	double theta_floor; //�Ƕ�����
	double theta_ceil; //�Ƕ�����
	/*int frame_length;
	int frame_width;
	int image_threshold;*/

	//int id;				//��Ʒid
	//string name;	//��Ʒ��
	//int price;			//��Ʒ�۸�
	//int num;			//��Ʒ����
};

class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//��ȡ��½��Ϣ
	void ReadLogin(CString &name, CString &pwd);

	//�޸�����
	void WritePwd(char* name, char* pwd);

	// ��ȡ��Ʒ����
	void ReadDocline(double &x_floor, double &x_ceil, double &y_floor, double &y_ceil, double &theta_floor, double &theta_ceil, int& hv_Threshold_8,
		int& hv_Filter_block_radius_8, int& rect_height, int& rect_width, int& m_startPos_left_8_x,
		int& m_startPos_left_8_y, int& m_startPos_right_8_x, int& m_startPos_right_8_y ,int &left_baoguang_time, int &right_baoguang_time);

	//��Ʒд���ļ�
	void WirteDocline(double& x_floor, double& x_ceil, double& y_floor, double& y_ceil, double& theta_floor, double& theta_ceil, int& hv_Threshold_8,
		int& hv_Filter_block_radius_8, int& rect_height, int& rect_width, int& m_startPos_left_8_x,
		int& m_startPos_left_8_y, int& m_startPos_right_8_x, int& m_startPos_right_8_y, int &left_baoguang_time, int &right_baoguang_time);
	//�������Ʒ
	//void Addline(CString name, int num, int price);

	list<msg> ls;	//�洢��Ʒ����
	//int num;			//������¼��Ʒ����
	
	
	CString DoubleToCString(double x);
	CString IntToCString(int x);
};



