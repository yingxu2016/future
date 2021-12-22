class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        start, end = list(), list()
        for i in range(len(intervals)):
            start.append(intervals[i][0])
            end.append(intervals[i][1])
            
        start.sort()
        end.sort()
        
        result = 0
        endIdx = 0
        for i in range(len(start)):
            if start[i] < end[endIdx]:
                result += 1
            else:
                endIdx += 1
        return result
