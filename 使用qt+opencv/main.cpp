#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QApplication>
#include <qwidget.h>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <string>
#include <QString>
#include <string>

using namespace cv;
using namespace std;

void show_pic(const string &path) {
    Mat srcImage = cv::imread(path);
    imshow("srcImage", srcImage);
    waitKey(0);
}

void show_window(const string &pic_path, const string &text){
    int argc = 0;
    char *argv[] = {nullptr};
    QApplication app (argc, argv); 
    QWidget window;
    QPushButton *button = new QPushButton("你点击我呀", &window);
    QLabel *label = new QLabel("结果会在这里显示", &window);
    QHBoxLayout *layout = new QHBoxLayout;
    QSpacerItem *spacerLeft1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *spacerLeft2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    layout->addWidget(button);
    layout->addStretch(1);
    layout->addWidget(label);
    layout->addStretch(1);
    window.setLayout(layout);

    layout->setStretchFactor(button, 4);
    layout->setStretchFactor(label, 2);

    QObject::connect(button, &QPushButton::clicked, [&](){
        show_pic(pic_path);
        label->setText(text.c_str());
        label->setStyleSheet("QLabel { color : red; }");
    });

    window.resize(400, 200);
    window.setWindowTitle("Here is the window");
    window.show();
    app.exec();
}



int main(int argc, char *argv[]) {
    show_window("./a.jpg", "你已经设置过了");
    return 0;
}