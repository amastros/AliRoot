#ifndef ALIMUONMCHVIEWAPPLICATION_H
#define ALIMUONMCHVIEWAPPLICATION_H

/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
* See cxx source for full Copyright notice                               */

// $Id$

/// \ingroup graphics
/// \class AliMUONMchViewApplication
/// \brief Main class for the mchview program
///
// Author Laurent Aphecetche, Subatech

#ifndef ROOT_TRint
#   include <TRint.h>
#endif

class AliMUONPainterMasterFrame;
class TGMainFrame;

class AliMUONMchViewApplication : public TRint
{
public:
  AliMUONMchViewApplication(const char* name, int* argc, char** argv, 
                            Float_t wfraction, Float_t hfraction);
  virtual ~AliMUONMchViewApplication();

  void HandleMenu(Int_t i);

  /// Return the version number of the mchview application
  static const char* Version() { return "0.93"; }
  
  /// Return the SVN revision  and version number of the mchview application
  static const char* FullVersion() { return Form("mchview Version %s ($Id$)",Version()); }
  
  void Open(const char* filename);

private:
  /// Not implemented
  AliMUONMchViewApplication(const AliMUONMchViewApplication& rhs);
  /// Not implemented
  AliMUONMchViewApplication& operator=(const AliMUONMchViewApplication& rhs);
  
  void CompareData();  
  void CreateMenuBar(UInt_t w);
  void Save();
  void Save(const char* filename);
  void Open();
  void PrintAs();
  void ReleaseNotes();
  
private:
  TGMainFrame* fMainFrame; ///< pointer to our mainframe
  AliMUONPainterMasterFrame* fPainterMasterFrame; ///< pointer to our main object
  
  static const Int_t fgkFILESAVEAS; ///< File/Save As... menu
  static const Int_t fgkFILEOPEN; ///< File/Open... menu
  static const Int_t fgkFILEEXIT; ///< File/Exit menu
  static const Int_t fgkFILEPRINTAS; ///< File/Print As... menu
  static const Int_t fgkABOUT; ///< About menu
  static const Int_t fgkCOMPAREDATA; ///< Tools/Compare Data menu
  
  static const char* fgkFileTypes[]; ///< For the open menu
  
  ClassDef(AliMUONMchViewApplication,4) // mchview application
};

#endif
