import hpscore2
import sys

if __name__ == "__main__":

    seq2="enwnnesenesswseeneseenwnenwwswnnneseenwnenwwswnwwsesswnwswnnenwnneseenwnenwwswnnenwnnesenesswseeenwnnesenesswsesswnwwseswseeneseneseenwnenwwswnnenwnnesenesswseeenwnnesenesswsesswnwwseswseenesswsesswnwswnnenwwswnwwseswseenessswnwwseswseeneseenwnnesenesswse"
    match = sys.argv[1]
    szMatch = len(match)
    seq = hpscore2.HPFold(match)
    maxscore = -1
    optStr = None
    for i in range(0, len(seq2)-szMatch+2):
	seq3=seq2[i:i+szMatch-1]
        absfold = hpscore2.make_absfold(seq3)
        relfold = hpscore2.make_relfold(seq3)
        if len(absfold) == len(seq) - 1:
  	    seq.SetAbsFold(absfold)
        elif len(relfold) == len(seq) - 1:
	    seq.SetRelFold(relfold)
        else:
	    pass
        sc = seq.PrintFold()
	if(sc > maxscore):
	    optStr = seq3
	    maxscore = sc
    print optStr
    print maxscore

