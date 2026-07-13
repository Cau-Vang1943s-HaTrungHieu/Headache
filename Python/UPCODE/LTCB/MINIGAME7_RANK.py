vn_golds, vn_silvers, vn_bronzes, thai_golds, thai_silvers, thai_bronzes = map(int, input().split())
method = int(input())

vn_total_medals = vn_golds + vn_silvers + vn_bronzes
thai_total_medals = thai_golds + thai_silvers + thai_bronzes

if method == 1:
    if (vn_total_medals > thai_total_medals): print("VN")
    elif (vn_total_medals < thai_total_medals): print("TL")
    else: print("TIE")
else:
    if (vn_golds > thai_golds): print("VN")
    elif (vn_golds < thai_golds): print("TL")
    else:
        if (vn_silvers > thai_silvers): print("VN")
        elif (vn_silvers < thai_silvers): print("TL")
        else:
            if (vn_bronzes > thai_bronzes): print("VN")
            elif (vn_bronzes < thai_bronzes): print("TL")
            else: print("TIE")