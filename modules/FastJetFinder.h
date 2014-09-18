/*
 *  Delphes: a framework for fast simulation of a generic collider experiment
 *  Copyright (C) 2012-2014  Universite catholique de Louvain (UCL), Belgium
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FastJetFinder_h
#define FastJetFinder_h

/** \class FastJetFinder
 *
 *  Finds jets using FastJet library.
 *
 *  $Date$
 *  $Revision$
 *
 *
 *  \author P. Demin - UCL, Louvain-la-Neuve
 *
 */

#include "classes/DelphesModule.h"

#include <map>

class TObjArray;
class TIterator;

namespace fastjet {
  class JetDefinition;
  class AreaDefinition;
  class Selector;
  namespace contrib {
    class NjettinessPlugin;
  }
}

class FastJetFinder: public DelphesModule
{
public:

  FastJetFinder();
  ~FastJetFinder();

  void Init();
  void Process();
  void Finish();

private:

  void *fPlugin; //!
  void *fRecomb; //!
  fastjet::contrib::NjettinessPlugin *fNjettinessPlugin; //!

  fastjet::JetDefinition *fDefinition; //!

  Int_t fJetAlgorithm;
  Double_t fParameterR;
  Double_t fJetPTMin;
  Double_t fConeRadius;
  Double_t fSeedThreshold;
  Double_t fConeAreaFraction;
  Int_t fMaxIterations;
  Int_t fMaxPairSize;
  Int_t fIratch;
  Int_t fAdjacencyCut;
  Double_t fOverlapThreshold;

  //-- N (sub)jettiness parameters --

  Bool_t fComputeNsubjettiness;
  Double_t fBeta;
  Int_t fAxisMode;
  Double_t fRcutOff;
  Int_t fN ;

  // --- FastJet Area method --------

  fastjet::AreaDefinition *fAreaDefinition;
  Int_t fAreaAlgorithm;
  Bool_t  fComputeRho;

  // -- ghost based areas --
  Double_t fGhostEtaMax;
  Int_t fRepeat;
  Double_t fGhostArea;
  Double_t fGridScatter;
  Double_t fPtScatter;
  Double_t fMeanGhostPt;

  // -- voronoi areas --
  Double_t fEffectiveRfact;

  std::map< Double_t, Double_t > fEtaRangeMap; //!

  TIterator *fItInputArray; //!

  const TObjArray *fInputArray; //!

  TObjArray *fOutputArray; //!
  TObjArray *fRhoOutputArray; //!

  ClassDef(FastJetFinder, 1)
};

#endif
