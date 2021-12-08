#!/usr/bin/python3
import re
import subprocess

numTimesToRace=50

timeRegex = re.compile(r'Time Elapsed: (\d+)s (\d+)ms (\d+)us (\d+)ns')

def raceCmd(cmd):
    sumTime = int(0)
    for i in range(numTimesToRace):
        result = subprocess.run(cmd, stdout=subprocess.PIPE)
        timeMatch = timeRegex.search(str(result.stdout))
        if timeMatch == None:
            raise RuntimeError("RegexFailed!!!")

        sumTime = sumTime + int(timeMatch[1]) * 1000000000 + int(timeMatch[2]) * 1000000 + int(timeMatch[3]) * 1000 + int(timeMatch[4])

    avgTime = int(sumTime / numTimesToRace)

    print("{}: {}s {}ms {}us {}ns".format(' '.join(cmd), int(avgTime/1000000000)%1000, int(avgTime/1000000)%1000, int(avgTime/1000)%1000, avgTime%1000))

for x in [ ['./day1.1'], ['./betterParse1.1'], ['./noParsing1.1'], ['./slidingWindow1.2'] ]:
    raceCmd(x)

#raceCmd(['./day1.1'])
#raceCmd(['./betterParse1.1'])
#raceCmd(['./noParsing1.1'])
