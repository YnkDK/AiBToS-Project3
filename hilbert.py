import hpscore
import sys

if __name__ == "__main__":

    seq2="enwnnesenesswseeneseenwnenwwswnnneseenwnenwwswnwwsesswnwswnnenwnneseenwnenwwswnnenwnnesenesswseeenwnnesenesswsesswnwwseswseeneseneseenwnenwwswnnenwnnesenesswseeenwnnesenesswsesswnwwseswseenesswsesswnwswnnenwwswnwwseswseenessswnwwseswseeneseenwnnesenesswse"
    match = sys.argv[1]
    szMatch = len(match)
    seq = hpscore.HPFold(match)
    maxscore = 0
    for i in range(0, len(seq2)-szMatch+2):
	seq3=seq2[i:i+szMatch-1]
        print seq3
        absfold = hpscore.make_absfold(seq3)
        relfold = hpscore.make_relfold(seq3)
        if len(absfold) == len(seq) - 1:
  	    seq.SetAbsFold(absfold)
        elif len(relfold) == len(seq) - 1:
	    seq.SetRelFold(relfold)
        else:
	    pass
        sc = seq.PrintFold()
	if(sc > maxscore):
	    maxscore = sc
    print maxscore
