#ifndef Timed_Message_Header  
#define Timed_Message_Header  

#include <QMessageBox>
#include <QPushButton>
#include <QTimer>

class TimedMessageBox : public QMessageBox
{
	Q_OBJECT

public:       
	TimedMessageBox(int timeoutSeconds, const QString & title, const QString & text, Icon icon, int button0, int button1, QWidget * parent=0)
					: QMessageBox(icon,title,text), _timeoutSeconds(timeoutSeconds+1), _text(text)
	{
		connect(&_timer, SIGNAL(timeout()), this, SLOT(Tick()));
		_timer.setInterval(1000);
	}

	virtual void showEvent(QShowEvent * e)
	{
		QMessageBox::showEvent(e);
		Tick();
		_timer.start();
	}

	private slots:
		void Tick()
		{
			if (--_timeoutSeconds >= 0) setText(_text.arg(_timeoutSeconds));
			else
			{
				_timer.stop();
				defaultButton()->animateClick();
			}
		}

private:
	QString _text;
	int _timeoutSeconds;
	QTimer _timer;
};

#endif