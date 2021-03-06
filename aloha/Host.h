//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef __ALOHA_HOST_H_
#define __ALOHA_HOST_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace aloha {

/**
 * Aloha host; see NED file for more info.
 */
class Host : public cSimpleModule
{
  private:
    // parameters
    simtime_t radioDelay;
    double txRate;
    cPar *iaTime;
    cPar *pkLenBits;
    simtime_t recvStartTime;
    simtime_t slotTime;
    simtime_t delay;
    bool isSlotted;
    long receiveCounter;


    // state variables, event pointers etc
    cModule *sf7;
    cModule *sf8;
    cModule *sf9;
    cModule *sf10;
    cModule *sf11;
    cModule *sf12;
    cMessage *endTxEvent;
    cMessage *endRxEvent;
    cMessage *endJoinEvent;
    cMessage *endJoinEvent2;
    cMessage *ack1;
    cMessage *ack2;
    cMessage *uplink;
    cMessage *payload;
    cMessage *ack0;
    cMessage *sleeep;
    enum { IDLE = 0, TRANSMIT = 1 , PRERECEIVE = 2, RECEIVE = 3, RECEIVE2=4, IDLE2 = 5, ACK=6, ACK2=7, SLEEP=8} state;
    simsignal_t channelStateSignal;
    simsignal_t receiveBeginSignal;
    simsignal_t receiveSignal;
    simsignal_t stateSignal;
    simtime_t timeout;
    int pkCounter;
    int pair;
    int distance;
    simtime_t sleeptime;

  public:
    Host();
    virtual ~Host();
    void setpair(int);
    int getpair();
    void setsleep(int);
    simtime_t getsleep();
    cModule *getadr();
    int getdistance();
    void setdatarate(double);

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void refreshDisplay() const override;
    simtime_t getNextTransmissionTime();

};

}; //namespace

#endif

