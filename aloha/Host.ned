//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//


//
// A computer in the ALOHAnet network.
//
simple Host
{
    parameters:
        @signal[state](type="long");
        @statistic[radioState](source="state"; title="Radio state"; enum="IDLE=0,TRANSMIT=1"; record=vector);
        @display("i=device/pc_s");
		@signal[receiveBegin](type="long");  // increases with each new frame arriving to the server and drops to 0 if the channel becomes finally idle
        @signal[receive](type="long");  // for successful receptions (non-collisions): 1 at the start of the reception, 0 at the end of the reception
        @signal[channelState](type="long");
		
		
        volatile int distance;    	      // distance of the host to the gateway in km
        double txRate @unit(bps);         // transmission rate
        double radioDelay @unit(s);       // propagation delay of radio link
        volatile int pkLenBits @unit(b);  // packet length in bits
        volatile double iaTime @unit(s);  // packet interarrival time
        double slotTime @unit(s);         // zero means no slots (pure Aloha)
    gates:
        input in @directIn;
}

