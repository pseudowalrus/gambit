/////////////////////////////////////////////////////////////////////////////
// Name:        led.h
// Purpose:     wxLed class
// Author:      Thomas Monjalon
// Created:     09/06/2005
// Revision:    09/06/2005
// Licence:     wxWidgets
/////////////////////////////////////////////////////////////////////////////

#ifndef WXLED_H
#define WXLED_H

#include <wx/window.h>
#include <wx/bitmap.h>
#include <wx/dcclient.h>
#include <wx/thread.h>

class wxLed : public wxWindow {
protected:
  char m_enabledColor[7];
  char m_disabledColor[7];
  char m_color[7];
  wxBitmap *m_bitmap;
  wxMutex m_mutex;

  void OnPaint(wxPaintEvent &event);
  virtual void SetBitmap(const char * color);

public:
  wxLed(wxWindow *parent, wxWindowID id, 
	const char *disabledColor = "000000", 
	const wxPoint &pos = wxDefaultPosition, 
	const wxSize &size = wxDefaultSize);
  ~wxLed();

  bool Enable(bool enable = true);
  void SetColor(const char *rgb);

private:
  DECLARE_EVENT_TABLE()
};

#endif // WXLED_H
