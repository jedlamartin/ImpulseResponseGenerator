/*
  ==============================================================================

    AudioData.h
    Created: 29 Jun 2025 4:34:31pm
    Author:  Martin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AudioData {
private:
    juce::AudioBuffer<float> buffer;
    double sampleRate;
public:
    juce::AudioBuffer<float>& getBuffer();
    void setSampleRate(double sampleRate);
};