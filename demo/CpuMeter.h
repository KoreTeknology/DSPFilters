#ifndef DSPDEMO_CPUMETER_H
#define DSPDEMO_CPUMETER_H

#include "Common.h"
#include "ResizableLayout.h"

/*
 * Simple CPU meter. Note this measures overall consumption in
 * the Audio callback (via Juce), not the overall system CPU usage.
 *
 */
class CpuMeter
  : public Component
  , public Timer
  , public ResizableLayout
{
public:
  CpuMeter (AudioDeviceManager& audioDeviceManager);
  ~CpuMeter ();

  void paint (Graphics& g);

private:
  void timerCallback ();

private:
  ScopedPointer<Label> m_label;
  AudioDeviceManager& m_audioDeviceManager;
  double m_value;
};

#endif