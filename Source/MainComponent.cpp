#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);

    selectExcitation.setButtonText("Browse");
    selectExcitation.onClick = [this]() {
        juce::FileChooser fileChooser("Select excitation file", juce::File(juce::File::getSpecialLocation(juce::File::SpecialLocationType::currentApplicationFile)), "");
        fileChooser.browseForFileToOpen();

        juce::AudioFormatManager manager;
        manager.registerBasicFormats();
        juce::AudioFormatReader* reader(manager.createReaderFor(fileChooser.getResult()));
        if (reader == nullptr) {
            return;
        }


        excitation.setSampleRate(reader->sampleRate);
        excitation.getBuffer().setSize(1, reader->lengthInSamples, false, false, true);
        if (!reader->read(&excitation.getBuffer(), 0, reader->lengthInSamples, 0, true, false)) {
            return;
        }
   
    };
    this->addAndMakeVisible(selectExcitation);
    



    selectAnswer.setButtonText("Browse");
    this->addAndMakeVisible(selectAnswer);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::FontOptions (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    selectExcitation.setBounds(0, 0, 100, 20);
    selectAnswer.setBounds(0, 40, 100, 20);
}
