/*
 * Copyright (c) 2003-2010 Rony Shapiro <ronys@users.sourceforge.net>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file PWSDragBar.cpp
* 
*/
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

////@begin includes
#include "PWSDragBar.h"
#include "passwordsafeframe.h"
#include "../../os/pws_tchar.h"
#include "../../corelib/PwsPlatform.h"
#include "../../corelib/ItemData.h"
#include "./wxutils.h"
////@end includes

////@begin XPM images
#include "./graphics/dragbar/new/Email.xpm"
#include "./graphics/dragbar/new/EmailX.xpm"
#include "./graphics/dragbar/new/Group.xpm"
#include "./graphics/dragbar/new/GroupX.xpm"
#include "./graphics/dragbar/new/Notes.xpm"
#include "./graphics/dragbar/new/NotesX.xpm"
#include "./graphics/dragbar/new/Password.xpm"
#include "./graphics/dragbar/new/PasswordX.xpm"
#include "./graphics/dragbar/new/Title.xpm"
#include "./graphics/dragbar/new/TitleX.xpm"
#include "./graphics/dragbar/new/URL.xpm"
#include "./graphics/dragbar/new/URLX.xpm"
#include "./graphics/dragbar/new/User.xpm"
#include "./graphics/dragbar/new/UserX.xpm"
////@end XPM images

IMPLEMENT_CLASS( PWSDragBar, CDragBar )

enum { DRAGBAR_TOOLID_BASE = 100 };

#define PWS_TOOLINFO(t, f) { wxSTRINGIZE_T(t), t, wxCONCAT(t, X), CItemData::f}

struct _DragbarElementInfo {
  const TCHAR* name;
  const char** bitmap;
  const char** bitmap_disabled;
  CItemData::FieldType ft;
} DragbarElements[] = { PWS_TOOLINFO(Group,     GROUP), 
                        PWS_TOOLINFO(Title,     TITLE), 
                        PWS_TOOLINFO(User,      USER), 
                        PWS_TOOLINFO(Password,  PASSWORD), 
                        PWS_TOOLINFO(Notes,     NOTES), 
                        PWS_TOOLINFO(URL,       URL), 
                        PWS_TOOLINFO(Email,     EMAIL)
                      };

PWSDragBar::PWSDragBar(PasswordSafeFrame* frame) : CDragBar(frame, this), m_frame(frame)
{
  for (int idx = 0; size_t(idx) < NumberOf(DragbarElements); ++idx) {
    AddTool(idx + DRAGBAR_TOOLID_BASE, wxBitmap(DragbarElements[idx].bitmap),
              wxString(_("Drag this image onto another window to paste the '"))
                      << DragbarElements[idx].name << _("' field."),
              wxBitmap(DragbarElements[idx].bitmap_disabled));
  }

}

PWSDragBar::~PWSDragBar()
{
}

wxString PWSDragBar::GetText(int id) const
{
  CItemData* item = m_frame->GetSelectedEntry();
  if (item) {
    return towxstring(item->GetFieldValue(DragbarElements[id-DRAGBAR_TOOLID_BASE].ft));
  }
  return wxEmptyString;
}

bool PWSDragBar::IsEnabled(int id) const
{
  const int idx = id - DRAGBAR_TOOLID_BASE;
  wxASSERT( idx >= 0 && size_t(idx) < NumberOf(DragbarElements));
  
  CItemData* item = m_frame->GetSelectedEntry();
  return item != 0 && item->GetFieldValue(DragbarElements[idx].ft).empty() == false;
}
