/**
    bespoke synth, a software modular synthesizer
    Copyright (C) 2021 Ryan Challinor (contact: awwbees@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
/*
  ==============================================================================

    AudioSplitter.h
    Created: 26 Aug 2023 7:18:00am
    Author:  Noxy Nixie

  ==============================================================================
*/

#pragma once

#include <iostream>
#include "IAudioProcessor.h"
#include "IDrawableModule.h"
#include "RollingBuffer.h"
#include "Ramp.h"
#include "PatchCableSource.h"

class AudioSplitter : public IAudioProcessor, public IDrawableModule
{
public:
   AudioSplitter();
   static IDrawableModule* Create() { return new AudioSplitter(); }
   static bool AcceptsAudio() { return true; }
   static bool AcceptsNotes() { return false; }
   static bool AcceptsPulses() { return false; }

   void CreateUIControls() override;
   bool CanMinimize() override { return false; }

   //IAudioSource
   void Process(double time) override;
   void PostRepatch(PatchCableSource* cableSource, bool fromUserClick) override;
   int GetNumTargets() override { return mDestinationCables.size(); }

   virtual void LoadLayout(const ofxJSONElement& moduleInfo) override;
   virtual void SetUpFromSaveData() override;

private:
   //IDrawableModule
   void DrawModule() override;
   void GetModuleDimensions(float& w, float& h) override;

   std::vector<PatchCableSource*> mDestinationCables;
};
