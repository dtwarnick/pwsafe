/*
 * Copyright (c) 2003-2020 Rony Shapiro <ronys@pwsafe.org>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file SafeCombinationCtrl.h
*
*/

#ifndef _SAFECOMBINATIONCTRL_H_
#define _SAFECOMBINATIONCTRL_H_

#include <wx/sizer.h> // Base class: wxBoxSizer
#include <wx/event.h> // Base class: wxEvtHandler

#include "core/StringX.h"

//without this class, we get 'pointer to member conversion via virtual base' error
class CommandEventHandler : public wxEvtHandler {
public:
  void HandleCommandEvent(wxCommandEvent& evt);
};

class SafeCombinationCtrl : virtual public wxBoxSizer, virtual CommandEventHandler {

public:
  SafeCombinationCtrl(wxWindow* parent, wxWindowID textCtrlID = wxID_ANY, StringX* valPtr = 0,
                       const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize)
    : wxBoxSizer(wxHORIZONTAL), m_textCtrl(0)
    { Init(parent, textCtrlID, valPtr, pos, size); }

 // Following c'tor for code autogenerated by DialogBlocks
 SafeCombinationCtrl(wxWindow* parent, wxWindowID textCtrlID, const wxString &, const wxPoint& pos, const wxSize& size, int)
   : wxBoxSizer(wxHORIZONTAL), m_textCtrl(0)
   { Init(parent, textCtrlID, nullptr, pos, size); }

  // following common c'tor code for both above
  void Init(wxWindow* parent, wxWindowID textCtrlID, StringX* valPtr, const wxPoint& pos, const wxSize& size);
  ~SafeCombinationCtrl();

  StringX GetCombination() const;
  void SetValidatorTarget(StringX* str);
  void SelectCombinationText() const;
  void AllowEmptyCombinationOnce(); // for YubiKey, one-shot for use in YubiBtn event handlers
  void SecureTextfield(bool secured);

private:
  wxTextCtrl* m_textCtrl;
};

#endif // _SAFECOMBINATIONCTRL_H_
