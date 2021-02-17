import os,sys,argparse

if not (os.getenv("MERGER_INPUT_DIR") and os.getenv("MERGER_OUTPUT_DIR")) :
    print "You need to source setup.sh"
    sys.exit()

# example usage: `python copyAndMergeRuns.py 32944` will copyAndMerge run 32944                                                                                                               
# or: `python copyAndMergeRuns.py 32944 32959` will copyAndMerge all runs from 32944-32959                                                                                                    
# or: `python copyAndMergeRuns.py 32944 32959 --skip "32945,32947,32948,32952"` will copyAndMerge all except for the four runs specified                                                      

# or change the following line and run via `python copyAndMergeRuns.py` (no other cmd line args)                                                                                              
runs = [32975,32976,32977,32978,32979,32980,32981,32982,32983,32984,32985]

p = argparse.ArgumentParser()
p.add_argument('startrun', type=int, nargs='?',default=None)
p.add_argument('endrun', type=int, nargs='?',default=None)
p.add_argument('--skip', default="", type=str)
args = p.parse_args()

if args.startrun :
    startrun = args.startrun
    if args.endrun :
        endrun = args.endrun
    else :
        endrun = startrun
    skipstr = args.skip

    skipruns = []
    if skipstr != "" :
        skipruns = map(int, (skipstr).split(",")) # turn str into list of ints                                                                                                                

    runs = []
    for run in range(startrun, endrun+1) :
        if run in skipruns :
            print "skipping run", run
            continue
        runs.append(run)

mergerdir = "/home/otsdaq/TestBeamAnalysis_T992/Merger/"

for run in runs :
    os.system("./megaCopy.csh %i |& tee megaCopylogs/%i.out;" % (run,run))
    os.system("%s/build/Merger %i |& tee %s/Mergerlogs/%i.out;" % (mergerdir,run,mergerdir,run))
