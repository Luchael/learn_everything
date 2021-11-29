def make_list(builded_list):
    price = {"공터" : 0,
            "주택" : 1,
            "편의점" : 2,
            "학교" : 4,
            "회사" : 6,
            "병원" : 10,
            "은행" : 20,
            "백화점" : 25,
            "호텔" : 30,
            "카지노" : 50,
            "항구" : 15,
            "경기장" : 15,
            "교회" : 0,
            "공장" : 0}
    builded_list_2, j = []+builded_list, 1
    for i in builded_list_2:
        builded_list.insert(j, price.get(i, 9))
        j+=2

    return (total_price(builded_list), builded_list_2)

def total_price(builded):
    for i in range(0, len(builded), 2):
        if (i!=0 or i!=12) and builded[i] == "항구":
            return 0
        if builded[i] == "공터":
            for j in range(i-1, i+4, 4):
                if 0 <= j < len(builded):
                    builded[j] *= 0.5
        elif builded[i] == '편의점':
            for j in range(i-6, i+7, 2):
                if (0 <= j < len(builded)) and builded[j] == '편의점' and j!=i:
                    builded[j+1] *= 0.7
            for j in range(i-4, i+5, 2):
                if (0 <= j < len(builded)) and (builded[j] in ['주택', '학교']) and j!=i:
                    builded[j+1] *= 4
        elif builded[i] == '학교':
            for j in range(i-8, i+9, 2):
                if (0 <= j < len(builded)) and j!=i and builded[j] == '주택':
                    builded[j+1] *= 4
            for j in range(i-4, i+5, 2):
                if (0 <= j < len(builded)) and j!=i and builded[j] == '호텔':
                    builded[j+1] *=0.5
        elif builded[i] == '회사':
            for j in range(i-8, i+9, 2):
                if (0 <= j < len(builded)) and j!=i and not (builded[j] in ['학교', '회사', '카지노']):
                    builded[j+1] *= 2
        elif builded[i] == '병원':
            for j in range(1, len(builded), 2):
                builded[j] *= 1.5
        elif builded[i] == '은행':
            for j in range(i-2, i+3, 4):
                if (0 <= j < len(builded)) and builded[j] == '회사':
                    builded[j+1] *= 5
        elif builded[i] == '백화점':
            for j in range(i-1, i+4, 4):
                if 0 <= j < len(builded):
                    builded[j] *= 3.5
            for j in range(0, len(builded), 2):
                if builded[j] == '편의점':
                    builded[j+1] *= 0
        elif builded[i] == '호텔':
            for j in range(0, len(builded), 2):
                if not (builded[j] in ['주택', '학교', '호텔', '카지노']):
                    builded[j+1] *= 2
                elif builded[j] == '주택':
                    builded[j+1] *= 0.5
        elif builded[i] == '카지노':
            for j in range(i-4, i+5, 2):
                if (0 <= j < len(builded)) and j!=i and builded[j] == '주택':
                    builded[j+1] *= 0.5
            for j in range(i-2, i+3, 4):
                if (0 <= j < len(builded)) and builded[j] == '호텔':
                    builded[j+1] *= 2
            for j in range(0, len(builded), 2):
                if builded[j] == '카지노':
                    builded[j+1] *= 0.5
        elif builded[i] == '항구':
            for j in range(0, len(builded), 2):
                if builded[j] in ['호텔', '카지노', '경기장']:
                    builded[j+1] *= 3
        elif builded[i] == '경기장':
            for j in range(i-3, i+6, 2):
                if (0 <= j < len(builded)) and j!=(i+1):
                    builded[j] *= 0.2
        elif builded[i] == '교회':
            for j in range(i-4, i+5, 2):
                if (0 <= j < len(builded)) and j!=i and (builded[j] in ['주택', '회사']):
                    builded[j+1] *= 1.5
        elif builded[i] == '공장':
            for j in range(i-5, i+8, 2):
                if (0 <= j < len(builded)) and j!=(i+1):
                    builded[j] *= 0
    total = 0
    for i in range(7):
        for j in range(1, len(builded), 2):
            if i == 5 and builded[j-1] == '경기장':
                total += builded[j]*4
            if i == 6 and "교회" in builded and builded[j-1] in ["주택", "회사"]:
                total += builded[j]*5
            else:
                total += builded[j]
    return total
Best = 0
Best_list = []
l = ["공터", "주택", "편의점", '학교', '회사','병원','은행','백화점','호텔','카지노','경기장','교회','공장', '항구']
for a in range(14):
    for b in range(13):
        print(a, b)
        for c in range(13):
            for d in range(13):
                for e in range(13):
                    for f in range(13):
                        for g in range(14):
                            h = make_list([l[a], l[b], l[c], l[d], l[e], l[f], l[g]])
                            if max(Best, h[0]) != Best:
                                Best, Best_list = h
                                print(Best, Best_list)
#result: 58016.0주 회사 백화점 백화점 백화점 호텔 회사 호텔
#건설하는데 드는 비용: 108000주
#1500 15000 15000 15000 30000 1500 30000