/*
  ==============================================================================

    AudioData.cpp
    Created: 29 Jun 2025 4:34:31pm
    Author:  Martin

  ==============================================================================
*/

#include "AudioData.h"

juce::AudioBuffer<float>& AudioData::getBuffer() {
    return buffer;
}

void AudioData::setSampleRate(double sampleRate){
    this->sampleRate = sampleRate;
}
