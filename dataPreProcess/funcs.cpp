#include "funcs.h"

QString s2q(const string &s)
{
	return QString(QString::fromLocal8Bit(s.c_str()));
}
string q2s(const QString &s)
{
	return string((const char *)s.toLocal8Bit());
}

bool sameName(const QString filename1, const QString filename2, int suffix)
{
	String filename1_sub = q2s(filename1).substr(0, filename1.length() - suffix);
	qDebug()<< s2q(filename1_sub);
	String filename2_sub = q2s(filename2).substr(0, filename1.length() - suffix);
	qDebug() << s2q(filename2_sub);

	if (filename1_sub.compare(filename2_sub)==0)
		return true;
	else
		return false;
}


Mat cut(Mat image, String flag)
{

	if (image.cols < image.rows)
	{
		int temp = (image.rows - image.cols) / 2;
		Mat result = image(Rect(0, temp, image.cols, image.cols));
		return result;
	}

	if (image.cols > image.rows)
	{
		int temp = (image.cols - image.rows);
		/*if (flag.compare("R") == 0)
		{
			qDebug() << QRect(temp, 0, image.cols, image.rows);
			Mat result = image(Rect(temp, 0, image.rows, image.rows));
			return result;
		}

		if (flag.compare("L") == 0)
		{
			Mat result = image(Rect(0, 0, image.rows, image.rows));
			return result;
		}*/

			Mat result = image(Rect(0, 0, image.rows, image.rows));
			return result;
	}

	return image;
}