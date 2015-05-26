#ifndef ALITPCSAMPAEMULATOR_H
#define ALITPCSAMPAEMULATOR_H


/**    @file AliTPCSAMPAEmulator.h
       @brief This the header File for the SAMPA class
 
       author: marian.ivanov@cern.ch
               mesut.arslandok@cern.ch  
*/


///////////////////////////////////////////////////////////////////////////////
//                        Class AliTPCSAMPAEmulator                          //
//  Class for emulation of the ALTRO chip (Altro digital Chain) in C++       //
///////////////////////////////////////////////////////////////////////////////

#include "TSystem.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <AliRawReader.h>
#include <AliTPCRawStreamV3.h>


using namespace std;

class AliTPCSAMPAEmulator : public TNamed {
public:
  AliTPCSAMPAEmulator();
  ~AliTPCSAMPAEmulator();
  //
  //
  Bool_t  BC3SlopeFilterFloat(Int_t npoints, Double_t *dataArray);
  static Bool_t  BC3SlopeFilterFloat(Int_t npoints, Double_t *dataArray, Double_t slopeDown, Double_t slopeUp, Double_t round);
  void SetBC3Parameters(Double_t slopeDown, Double_t slopeUp, Double_t round);
  //
  // Bool_t  MovingAverageFilter(Int_t npoints, Double_t *dataArray);
  //Bool_t  MovingAverageFilter(Int_t npoints, Double_t *dataArray, Double_t length, Double_t skipDiff);
private:
  AliTPCSAMPAEmulator(const AliTPCSAMPAEmulator &sig);
  AliTPCSAMPAEmulator& operator = (const  AliTPCSAMPAEmulator &source);
public:
  //
  // BC3 parameters
  //
  Double_t  fBC3SlopeDown;  // BC3 slope down parameter
  Double_t  fBC3SlopeUp;    // BC3 slope up   parameter
  Double_t  fBC3Round;      // Rounding error of BC3 filter
  ClassDef(AliTPCSAMPAEmulator,1);
};
#endif
