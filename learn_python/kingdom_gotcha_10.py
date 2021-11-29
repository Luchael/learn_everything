import random
def ancient(a):
    return {1:'퓨어바닐라'}.get(a,9)
def epic(a):
    return {1:'구미호',
            2:'에스프레소',
            3:'호밀',
            4:'마들렌',
            5:'칠리',
            6:'감초',
            7:'뱀파이어',
            8:'허브',
            9:'스파클링',
            10:'석류',
            11:'정글전사',
            12:'웨어울프',
            13:'민트초코',
            14:'다크초코',
            15:'자색고구마',
            16:'우유',
            17:'독버섯',
            18:'눈설탕',
            19:'라떼',
            20:'아몬드',
            21:'블랙레이즌',
            22:'딸기크레페'}.get(a,9)
def rare(a):
    return {1:'용사',
            2:'체리',
            3:'팬케이크',
            4:'당근',
            5:'공주',
            6:'연금술사',
            7:'아보카도',
            8:'탐험가',
            9:'블랙베리',
            10:'버블껌',
            11:'양파',
            12:'클로버',
            13:'커스터드'}.get(a,9)
def common(a):
    return{1:'용감',
           2:'딸기',
           3:'마법사',
           4:'닌자',
           5:'천사',
           6:'근육',
           7:'비트'}.get(a,9)
p=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
anc, anc_s, epi, epi_s, rar, rar_s, com, com_s = 0, 0, 0, 0, 0, 0, 0, 0
i=int(input("가챠 횟수를 입력해주세요 : "))
for k in range(0,i//10+1):
    for j in range(0,10):
        s=random.random()
        if(s<0.00054):
            q=random.randint(0,1)
            p[q]=p[q]+1
            anc+=1
        elif(s<0.00362):
            q=random.randint(1,2)
            p[q]=p[q]+1
            anc_s+=1
        elif(s<0.03244):
            q=random.randint(2,24)
            p[q]=p[q]+1
            epi+=1
        elif(s<0.19634):
            q=random.randint(24,46)
            p[q]=p[q]+1
            epi_s+=1
        elif(s<0.250003):
            q=random.randint(46,59)
            p[q]=p[q]+1
            rar+=1
        elif(s<0.57646):
            q=random.randint(59,72)
            p[q]=p[q]+1
            rar_s+=1
        elif(s<(0.67341+0.00011/7)):
            q=random.randint(72,79)
            p[q]=p[q]+1
            com+=1
        else:
            q=random.randint(79,86)
            p[q]=p[q]+1
            com_s+=1
for j in range(0,i-k*10):
    s=random.random()
    if(s<0.00054):
        q=random.randint(0,1)
        p[q]=p[q]+1
        anc+=1
    elif(s<0.00362):
        q=random.randint(1,2)
        p[q]=p[q]+1
        anc_s+=1
    elif(s<0.03244):
        q=random.randint(2,24)
        p[q]=p[q]+1
        epi+=1
    elif(s<0.19634):
        q=random.randint(24,46)
        p[q]=p[q]+1
        epi_s+=1
    elif(s<0.250003):
        q=random.randint(46,59)
        p[q]=p[q]+1
        rar+=1
    elif(s<0.57646):
        q=random.randint(59,72)
        p[q]=p[q]+1
        rar_s+=1
    elif(s<(0.67341+0.00011/7)):
        q=random.randint(72,79)
        p[q]=p[q]+1
        com+=1
    else:
        q=random.randint(79,86)
        p[q]=p[q]+1
        com_s+=1
s='고대\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
for j in range(0,86):
    if(j<1):
        s+='%s: %d  ' % (ancient(j+1),p[j])
        if(j==0):
            s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n고대영혼석\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
        elif((j+1)%5==0):
            s+='\n'
    elif(j<2):
        s+='%s영혼석 : %d  ' % (ancient(j),p[j])
        if(j==1):
            s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n에픽\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
        elif(j%5==0):
            s+='\n'
    elif (j<24):
        s+='%s: %d  ' % (epic(j-1),p[j])
        if(j==23):
            s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n에픽영혼석\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
        elif((j-1)%5==0):
            s+='\n'
    elif(j<46):
        s+='%s영혼석 : %d  ' % (epic(j-23),p[j])
        if(j==45):
            s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n레어\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
        elif((j-23)%5==0):
            s+='\n'
    elif (j<59):
        s+='%s: %d  ' % (rare(j-45),p[j])
        if(j==58):
            s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n레어영혼석\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
        elif((j-45)%5==0):
            s+='\n'
    elif(j<72):
        s+='%s영혼석 : %d  ' % (rare(j-58),p[j])
        if(j==71):
            s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n일반\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
        elif((j-58)%5==0):
            s+='\n'
    elif (j<79):
        s+='%s: %d  ' % (common(j-71),p[j])
        if(j==78):
            s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n일반영혼석\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n'
        elif((j-71)%5==0):
            s+='\n'
    elif(j<86):
        s+='%s영혼석 : %d  ' % (common(j-78),p[j])
        if((j-78)%5==0):
            s+='\n'
s+='\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n총 결과\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n고대: %d\t\t에픽: %d\t\t레어: %d\t\t일반: %d\n합계: %d\n고대영혼석: %d\t\t에픽영혼석: %d\t레어영혼석: %d\t일반영혼석: %d\n합계: %d\n---------------------------------------------------------------------------------------------------------------------------------------------------------------\n' % (anc, epi, rar, com, anc+epi+rar+com, anc_s, epi_s, rar_s, com_s, anc_s+epi_s+rar_s+com_s)
print(s)