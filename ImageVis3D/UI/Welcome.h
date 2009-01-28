/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2008 Scientific Computing and Imaging Institute,
   University of Utah.

   
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/


//!    File   : Welcome.h
//!    Author : Jens Krueger
//!             SCI Institute
//!             University of Utah
//!    Date   : January 2009
//
//!    Copyright (C) 2008 SCI Institute

#ifndef WELCOME_H
#define WELCOME_H

#include "AutoGen/ui_Welcome.h"
#include <vector>
#include <string>

class MRUButton : public QPushButton {
  public:
    explicit MRUButton(QWidget *parent=0) : QPushButton(parent) {}
    explicit MRUButton(const QString &text, QWidget *parent=0) : QPushButton(text, parent) {}
    MRUButton(const QIcon& icon, const QString &text, QWidget *parent=0) : QPushButton(icon, text, parent) {}
    virtual ~MRUButton() {}

    std::string  strFilename;
};


class WelcomeDialog : public QDialog, protected Ui_Welcome
{
  Q_OBJECT
  public:
    WelcomeDialog(QWidget* parent, Qt::WindowFlags flags = 0);
    virtual ~WelcomeDialog();
  
    void ClearMRUItems();
    void AddMRUItem(std::string strDesc, std::string strFilename);
    void SetShowAtStartup(bool bShow) {checkBox_ShowAtStartup->setChecked(!bShow);}
    bool ShowAtStartup() const {return !checkBox_ShowAtStartup->isChecked();}

  protected slots:
    virtual void CheckUpdates();
    virtual void OnlineVideoTut();
    virtual void OnlineHelp();
    virtual void OpenFromFile();
    virtual void OpenFromDir();
    virtual void OpenMRU();

  signals:
    void CheckUpdatesClicked();
    void OnlineVideoTutClicked();
    void OnlineHelpClicked();
    void OpenFromFileClicked();
    void OpenFromFileClicked(std::string filename);
    void OpenFromDirClicked();
    void OpenMRU(int iID);

  private:
    std::vector<MRUButton*> m_vMRUItems;


};

#endif // WELCOME_H
