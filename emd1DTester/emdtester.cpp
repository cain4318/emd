#include "emdtester.h"

EMDtester::EMDtester(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	signalMapper = new QSignalMapper(this);

	connect(ui.btn_showSdis, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_showSdis, "show supply distribute");
	connect(ui.btn_showDdis, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_showDdis, "show demand distribute");
	connect(ui.btn_randomData, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_randomData, "rand Data");
	connect(ui.btn_calemd, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calemd, "Cal EMD");
	connect(ui.btn_calGrad, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calGrad, "Cal Grad");
	connect(ui.btn_calemd_ap, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calemd_ap, "Cal EMD ap");
	connect(ui.btn_calGrad_ap, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_calGrad_ap, "Cal Grad ap");
	connect(ui.btn_saveTest, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_saveTest, "Save Test");
	connect(ui.btn_saveTest_ap, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_saveTest_ap, "Save Test ap");
	connect(ui.btn_readSingleData, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_readSingleData, "..");
	connect(ui.btn_readInSD, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_readInSD, "load");
	connect(ui.btn_readBatchData, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_readBatchData, "...");
	connect(ui.btn_readInBD, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(ui.btn_readInBD, "batch");


	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));

	connect(this, SIGNAL(showSupplyDistributeSignal(bool)), this, SLOT(showSupplyDistributeSlot(bool)));
	connect(this, SIGNAL(showDemandDistributeSignal(bool)), this, SLOT(showDemandDistributeSlot(bool)));
	connect(this, SIGNAL(generateRandDataSignal()), this, SLOT(generateRandDataSlot()));
	connect(this, SIGNAL(calEMDDisSignal()), this, SLOT(calEMDDisSlot()));
	connect(this, SIGNAL(calEMDGradSignal()), this, SLOT(calEMDGradSlot()));
	connect(this, SIGNAL(calApEMDDisSignal()), this, SLOT(calApEMDDisSlot()));
	connect(this, SIGNAL(calApEMDGradSignal()), this, SLOT(calApEMDGradSlot()));
	connect(this, SIGNAL(saveTestResSignal()), this, SLOT(saveTestResSlot()));
	connect(this, SIGNAL(saveApTestResSignal()), this, SLOT(saveApTestResSlot()));
	connect(this, SIGNAL(setRootPathSignal()), this, SLOT(setRootPathSlot()));
	connect(this, SIGNAL(setResPathSignal()), this, SLOT(setResPathSlot()));
	connect(this, SIGNAL(loadSingleDataSignal()), this, SLOT(loadSingleDataSlot()));
	connect(this, SIGNAL(loadBatchDataSignal()), this, SLOT(loadBatchDataSlot()));

	connect(ui.sb_nDim, SIGNAL(valueChanged(int)), this, SLOT(changeDimNumSlot(int)));
}


EMDtester::~EMDtester()
{

}



void EMDtester::doClicked(const QString & btnname)
{
	if (btnname == "show supply distribute")
		emit showSupplyDistributeSignal(true);

	if (btnname == "show demand distribute")
		emit showDemandDistributeSignal(true);

	if (btnname == "rand Data")
		emit generateRandDataSignal();

	if (btnname == "Cal EMD")
		emit calEMDDisSignal();

	if (btnname == "Cal Grad")
		emit calEMDGradSignal();

	if (btnname == "Cal EMD ap")
		emit calApEMDDisSignal();

	if (btnname == "Cal Grad ap")
		emit calApEMDGradSignal();

	if (btnname == "Save Test")
		emit saveTestResSignal();

	if (btnname == "Save Test ap")
		emit saveApTestResSignal();

	if (btnname == "..")
		emit setRootPathSignal();

	if (btnname == "load")
		emit setResPathSignal();

	if (btnname == "...")
		emit loadSingleDataSignal();

	if (btnname == "batch")
		emit loadBatchDataSignal();
}
void EMDtester::changeDimNumSlot(int newDim)
{
	ndim = newDim;
	//qDebug() << ndim;
}

void EMDtester::showSupplyDistributeSlot(bool showHis)
{
	QString data = ui.t_supplyData->toPlainText();
	QStringList dataList = data.split(",");
	int total_dim = dataList.size();
	select_Ssum = 0;
	sumSupply = 0;

	if (total_dim<ndim)
		QMessageBox::warning(this, tr("error"), tr("supply data not enough"), QMessageBox::Yes | QMessageBox::No);
	else{
	Sdata.clear();
	for (int i = 0; i < ndim; i++)
	{
		float temp_data = dataList.at(i).toFloat();
		Sdata.push_back(temp_data);
		select_Ssum += temp_data;
	}

	sumSupply = select_Ssum;
	for (int i = ndim; i < total_dim; i++)
	{
		sumSupply += dataList.at(i).toFloat();
	}

	QString lb_s = QString("%1(%2)/%3(%4)").arg(select_Ssum).arg(ndim).arg(sumSupply).arg(total_dim);
	ui.t_sumS->setText(lb_s);

	sigS = initData(Sdata, ndim);
	if (showHis)
		drawHis(Sdata, "supply data distribute");
	
	}
	
}


void EMDtester::showDemandDistributeSlot(bool showHis)
{

	QString data = ui.t_demandData->toPlainText();
	QStringList dataList = data.split(",");
	int total_dim = dataList.size();
	sumDemand = 0;
	select_Dsum = 0;

	if (total_dim<ndim)
		QMessageBox::warning(this, tr("error"), tr("supply data not enough"), QMessageBox::Yes | QMessageBox::No);
	else{
		Ddata.clear();
		for (int i = 0; i < ndim; i++)
		{
			float temp_data = dataList.at(i).toFloat();
			Ddata.push_back(temp_data);
			select_Dsum += temp_data;
		}

		sumDemand = select_Dsum;
		for (int i = ndim; i < total_dim; i++)
		{
			sumDemand += dataList.at(i).toFloat();
		}

		QString lb_d = QString("%1(%2)/%3(%4)").arg(select_Dsum).arg(ndim).arg(sumDemand).arg(total_dim);
		ui.t_sumD->setText(lb_d);

		sigD = initData(Ddata, ndim);
		if (showHis)
			drawHis(Ddata, "demand data distribute");

	}

}


void EMDtester::generateRandDataSlot()
{
	srand((unsigned)time(NULL));

	int temp_sd = 0;// rand() % 100;
	int temp_dd = 0;// rand() % 100;

	float sum_s = temp_sd;
	float sum_d = temp_dd;
	float new_sum_d = 0;
	float new_sum_s = 0;
	String sd = "";// to_string(temp_sd);
	String dd = "";// to_string(temp_dd);


	//for (int i = 1; i < ndim-1; i++)
	//{
	//	temp_sd = rand() % 100;
	//	sum_s += temp_sd;
	//	sd.append(",").append(to_string(rand() % 100));
	//}



	vector<int> d_data;
	vector<int> s_data;
	//s_data.push_back(temp_sd);
	//d_data.push_back(temp_dd);

	for (int i = 0; i <= ndim-2; i++)
	{
		temp_dd = rand() % 100;
		sum_d += temp_dd;
		d_data.push_back(temp_dd);

		temp_sd = rand() % 100;
		sum_s += temp_sd;
		s_data.push_back(temp_sd);
	}

	if (sum_s < sum_d)
	{
		for (int i = 0; i <= ndim - 2; i++)
		{
			temp_dd = d_data.at(i)*sum_s / sum_d;
			new_sum_d += temp_dd;
			if (i == 0){
				dd.append(to_string(temp_dd));
				sd.append(to_string(s_data.at(i)));
			}
			else{
				dd.append(",").append(to_string(temp_dd));
				sd.append(",").append(to_string(s_data.at(i)));
			}
		}
		int last_dim = sum_s - new_sum_d;
		temp_sd = rand() % 100;
		temp_dd = temp_sd + last_dim;
	}
	else
	{
		for (int i = 0; i <= ndim - 2; i++)
		{
			temp_sd = s_data.at(i)*sum_d / sum_s;
			new_sum_s += temp_sd;
			if (i == 0){
				sd.append(to_string(temp_sd));
				dd.append(to_string(d_data.at(i)));
			}
			else{
				sd.append(",").append(to_string(temp_sd));
				dd.append(",").append(to_string(d_data.at(i)));
			}
		}
		int last_dim = sum_d - new_sum_s;
		temp_dd = rand() % 100;
		temp_sd = temp_dd + last_dim;
	}

	sd.append(",").append(to_string(temp_sd));
	dd.append(",").append(to_string(temp_dd));

	ui.t_supplyData->setText(s2q(sd));
	ui.t_demandData->setText(s2q(dd));
}

Mat EMDtester::initData(vector<float> data, int ndim)
{
	Mat sig = Mat::zeros(ndim, 2, CV_32FC1);
	for (int i = 0; i < ndim; i++)
	{
		sig.at<float>(i * 2) = data.at(i);
		sig.at<float>(i * 2 + 1) = i;
	}
	return sig;
}

void EMDtester::calEMDDisSlot()
{ 
	if (sigS.rows != ndim * 2)
		showSupplyDistributeSlot(false);
	if (sigD.rows != ndim * 2)
		showDemandDistributeSlot(false);

	emdDis = EMD(sigS, sigD, CV_DIST_L2, 0, 0, plan);
	ui.lb_emdDis->setText(QString("%1").arg(emdDis));
}

void EMDtester::calEMDGradSlot()
{
	calEMDDisSlot();
	gradRes.clear();
	for (int i = 0; i < ndim; i++)
	{
		float temp_emd = calDeltaGrad(i,"emd");
		if (temp_emd == -1){
			qDebug() << " out of bound in calDeltaGrad()";
			return;
		}
		float temp_grad = (temp_emd - emdDis) / delta;
		gradRes.push_back(temp_grad);
	}

	drawGradHis(gradRes, "grad");
}

void EMDtester::calApEMDDisSlot()
{
	if (sigS.rows != ndim * 2)
		showSupplyDistributeSlot(false);
	if (sigD.rows != ndim * 2)
		showDemandDistributeSlot(false);

	emdDis_ap = emd_ap(Sdata, Ddata);
	ui.lb_emdDis_ap->setText(QString("%1").arg(emdDis_ap));
}

void EMDtester::calApEMDGradSlot()
{
	calEMDDisSlot();
	gradRes_ap.clear();
	gradRes_ap = emdGrad_ap(Sdata, Ddata);

	drawGradHis(gradRes_ap, "grad_ap");
	calAApEMDGradSlot();
}

//void EMDtester::calAApEMDGradSlot()
//{
//	calEMDDisSlot();
//	gradRes_aap.clear();
//	gradRes_aap = emdGrad_ap(Sdata, Ddata);
//
//	int maxGrad = INT_MIN;
//	int minGrad = INT_MAX;
//	for (int i = 0; i < gradRes_aap.size(); i++)
//	{
//		if (gradRes_aap.at(i) > maxGrad)
//			maxGrad = gradRes_aap.at(i);
//		if (gradRes_aap.at(i)<minGrad)
//			minGrad = gradRes_aap.at(i);
//	}
//
//
//	for (int i = 0; i < gradRes_aap.size(); i++)
//	{
//		if (select_Ssum > select_Dsum)
//		{
//			int temp = gradRes_aap.at(i);
//			int temp2 = -(gradRes_aap.at(i) - maxGrad);
//			gradRes_aap.at(i) = -(gradRes_aap.at(i) - maxGrad);
//		}
//		else
//		{
//			int temp = gradRes_aap.at(i);
//			int temp2 = -(gradRes_aap.at(i) - minGrad);
//			gradRes_aap.at(i) = -(gradRes_aap.at(i) - minGrad);
//		}
//		
//	}
//	drawGradHis(gradRes_aap, "grad_aap");
//}
void EMDtester::calAApEMDGradSlot()
{
	calApEMDDisSlot();
	gradRes_aap.clear();
	for (int i = 0; i < ndim; i++)
	{
		float temp_emd = calDeltaGrad(i,"emd_ap");
		if (temp_emd == -1){
			qDebug() << " out of bound in calDeltaGrad()";
			return;
		}
		float temp_grad = (temp_emd - emdDis) / delta;
		gradRes_aap.push_back(temp_grad);
	}

	drawGradHis(gradRes_aap, "grad_app");
}

float EMDtester::calDeltaGrad(int index,String method)
{
	if (index >= sigD.rows){
		return -1;
	}
	else
	{
		//float last_data = sigD.at<float>(index * 2);
		int N = sigD.rows;
		for (int i = 0; i < sigD.rows; i++)
		{
			if (i != index){
				sigD.at<float>(i * 2) -= delta;
				Ddata.at(i) -= delta;
			}
			else{
				sigD.at<float>(i * 2) += (N - 1)*delta;
				Ddata.at(i) += (N - 1)*delta;
			}
		}
		//sigD.at<float>(index * 2) += delta;
		Mat flow_opencv;
		float emd_grad = 0;
		if (method=="emd")
			emd_grad = EMD(sigS, sigD, CV_DIST_L2, 0, 0, flow_opencv);
		if (method == "emd_ap")
			emd_grad = emd_ap(Sdata, Ddata);
		for (int i = 0; i < sigD.rows; i++)
		{
			if (i != index){
				sigD.at<float>(i * 2) += delta;
				Ddata.at(i) += delta;
			}
			else{
				sigD.at<float>(i * 2) -= (N - 1)*delta;
				Ddata.at(i) -= (N - 1)*delta;
			}

		}
		//sigD.at<float>(index * 2) -= delta; 
		return emd_grad;
	}
}

void EMDtester::saveTestResSlot()
{
	nowtime = time(NULL);
	String seconds = to_string(nowtime);

	//save data
	String filename_img =savePath+ seconds+ ".jpg";
	String filename_data = savePath + seconds + ".txt";
	saveTestData(Sdata, Ddata, gradRes,emdDis, plan, filename_data);

	//save image
	saveImage(Sdata, Ddata, gradRes, filename_img);
}

void EMDtester::saveApTestResSlot()
{
	calEMDGradSlot();
	calApEMDGradSlot();
	calAApEMDGradSlot();

	nowtime = time(NULL);
	String seconds = to_string(nowtime);

	//save data
	String filename_img = savePath_ap + seconds + ".jpg";
	String filename_data = savePath_ap + seconds + ".txt";
	saveTestData(Sdata, Ddata, gradRes,gradRes_ap, emdDis,emdDis_ap, plan, filename_data);

	//save image
	//saveImage(Sdata, Ddata, gradRes, gradRes_ap, filename_img);
	saveImage(Sdata, Ddata, gradRes, gradRes_ap, gradRes_aap, filename_img);
	Sdata.clear();
	Ddata.clear();
	gradRes.clear();
	gradRes_ap.clear();
	gradRes_aap.clear();
}

void EMDtester::setRootPathSlot(){ qDebug() << "5"; }
void EMDtester::setResPathSlot(){ qDebug() << "6"; }
void EMDtester::loadSingleDataSlot(){ qDebug() << "7"; }
void EMDtester::loadBatchDataSlot()
{
	fstream fs;
	String filename = "dis.txt";
	String filename_ap = "dis_ap.txt";
	for (int i = 0; i < 300; i++)
	{
		generateRandDataSlot();
		_sleep(1000);
		qDebug() << i << "\n";
		calEMDDisSlot();
		calApEMDDisSlot();
		fs.open(filename, fstream::in | fstream::out | fstream::app);
		fs << emdDis << "\n";
		fs.close();

		fs.open(filename_ap, fstream::in | fstream::out | fstream::app);
		fs << emdDis_ap << "\n";
		fs.close();

		//saveApTestResSlot();

	}

}