
# 내가 쓴 코드
def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    

    
    for i in range(len(completion)):
        if participant[i] != completion[i]:
            return participant[i]
    
    
    return participant[-1]


# 모범

import collections


def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]