#include "Panel.h"

Panel::Panel(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Panel) {
    ui->setupUi(this);
}

Panel::~Panel() {
    delete ui;
}
