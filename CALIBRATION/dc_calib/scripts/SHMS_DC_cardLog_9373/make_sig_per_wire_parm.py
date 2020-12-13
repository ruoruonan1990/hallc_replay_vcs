#Script to generate sigma per wire parameter file for Hall C Drift Chambers
#NOTE: Make sure to verify the DC parameters match in the hallc_replay/PARAM/S(HMS)/DC/p(h)dc_geom.param file

import numpy as np


#Choose spectrometer arm (User Input)
spec = "p"  # "h": HMS, "p": SHMS

if spec=="p":
    #set plane names
    pl_names = np.array(["1u1", "1u2", "1x1", "1x2", "1v1", "1v2", "2v2", "2v1", "2x2", "2x1", "2u2", "2u1"])
    pl_nwires = np.array([107, 107, 79, 79, 107, 107, 107, 107, 79, 79, 107, 107])

elif spec=="h":
    #set plane names
    pl_names = np.array(["1u1", "1u2", "1x1", "1x2", "1v2", "1v1", "2v1", "2v2", "2x2", "2x1", "2u2", "2u1"])
    pl_nwires = np.array([96, 96, 102, 102, 96, 96, 96, 96, 102, 102, 96, 96])

    
#Set param file name
fname = "%sdc_sig_per_wire.param"%(spec)
f = open(fname, "w")

#write parameters to file
comments = """; This parameter file gives the sigma for the wire residuals in [cm]
; The user may change the sigma parameter of individual wires, if need be.
; Refer to hcama/src/THcDriftChamberPlane.cxx for additional information of 
; how the parameters are implemented. (hint: look for 'fSigmaWire')\n
"""
param_flag = "%sdc_using_sigma_per_wire=1\n" %(spec)
f.write(comments)
f.write(param_flag)
#loop over each plane
for i, ipl in enumerate(pl_names):
    print("\nwire_sigma%s="%(ipl))
    f.write("\nwire_sigma%s=\n"%(ipl))

    #reset counter to zero
    cnt = 0

    #loop over each wire of a given plane
    for j in range(pl_nwires[i]):
        
        sigma = 0.0240  #set each wire 240 um (or 0.00240 cm) sigma for residuals

        #do not end line if counter <10
        f.write("%s, "%(sigma))

        #wire counter (used to keep track of only up to 10 entries per line)
        cnt = cnt+1
        
        #check if counter reached 10 entries (0-9), if so, change to new line
        if(cnt==10 or j==(pl_nwires[i]-1)):
            #print("reached end of line -----------")
            f.write("\n") #write new line

            cnt=0   #reset countes

        
            
        
f.close()

