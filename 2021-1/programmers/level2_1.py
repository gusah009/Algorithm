def solution(cacheSize, cities):
    answer = 0
    my_dict = {}
    my_cache = 0
    lru = 0
    for city in cities:
        city = city.lower()
        lru += 1
        if city in my_dict:
            my_dict[city] = lru
            answer += 1
        else:
            if my_cache < cacheSize:
                my_dict[city] = lru
                my_cache += 1
            else:
                if cacheSize != 0:
                    key_min = min(my_dict.keys(), key=(lambda k: my_dict[k]))
                    del my_dict[key_min]
                    my_dict[city] = lru
            answer += 5
    return answer

