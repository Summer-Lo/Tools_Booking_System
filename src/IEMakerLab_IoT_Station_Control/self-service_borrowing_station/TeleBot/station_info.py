# Line full name
line = {'AEL':'Airport Express',\
        'TCL':'Tung Chung Line',\
        'TML':'Tuen Ma Line',\
        'TKL':'Tseung Kwan O Line',\
        'EAL':'East Rail Line'}

# Station Full name
sta = {\
    # AEL Airport Express
    'HOK' : 'Hong Kong',\
    'KOW' :'Kowloon',\
    'TSY' :'Tsing Yi',\
    'AIR' :'Airport',\
    'AWE' :'AsiaWorld Expo',\
    # TCL Tung Chung Line
    'HOK' : 'Hong Kong',\
    'KOW' : 'Kowloon',\
    'OLY' : 'Olympic',\
    'NAC' : 'Nam Cheong',\
    'LAK' : 'Lai King',\
    'TSY' : 'Tsing Yi',\
    'SUN' : 'Sunny Bay',\
    'TUC' : 'Tung Chung',\
    # TML Tuen Ma Line
    'WKS' : 'Wu Kai Sha',\
    'MOS' : 'Ma On Shan',\
    'HEO' : 'Heng On',\
    'TSH' : 'Tai Shui Hang',\
    'SHM' : 'Shek Mun',\
    'CIO' : 'City One',\
    'STW' : 'Sha Tin Wai',\
    'CKT' : 'Che Kung Temple',\
    'TAW' : 'Tai Wai',\
    'HIK' : 'Hin Keng',\
    'DIH' : 'Diamond Hill',\
    'KAT' : 'Kai Tak',\
    'SUW' : 'Sung Wong Toi',\
    'TKW' : 'To Kwa Wan',\
    'HOM' : 'Ho Man Tin',\
    'HUH' : 'Hung Hom',\
    'ETS' : 'East Tsim Sha Tsui',\
    'AUS' : 'Austin',\
    'NAC' : 'Nam Cheong',\
    'MEF' : 'Mei Foo',\
    'TWW' : 'Tsuen Wan West',\
    'KSR' : 'Kam Sheung Road',\
    'YUL' : 'Yuen Long',\
    'LOP' : 'Long Ping',\
    'TIS' : 'Tin Shui Wai',\
    'SIH' : 'Siu Hong',\
    'TUM' : 'Tuen Mun',\
    # TKL Tseung Kwan O Line
    'NOP' : 'North Point',\
    'QUB' : 'Quarry Bay',\
    'YAT' : 'Yau Tong',\
    'TIK' : 'Tiu Keng Leng',\
    'TKO' : 'Tseung Kwan O',\
    'LHP' : 'LOHAS Park',\
    'HAH' : 'Hang Hau',\
    'POA' : 'Po Lam',\
    # EAL East Rail Line
    'ADM' : 'Admiralty',\
    'EXC' : 'Exhibition Centre',\
    'HUH' : 'Hung Hom',\
    'MKK' : 'Mong Kok East',\
    'KOT' : 'Kowloon Tong',\
    'TAW' : 'Tai Wai',\
    'SHT' : 'Sha Tin',\
    'FOT' : 'Fo Tan',\
    'RAC' : 'Racecourse',\
    'UNI' : 'University',\
    'TAP' : 'Tai Po Market',\
    'TWO' : 'Tai Wo',\
    'FAN' : 'Fanling',\
    'SHS' : 'Sheung Shui',\
    'LOW' : 'Lo Wu',\
    'LMC' : 'Lok Ma Chau'}

sta_AEL = {\
    # AEL Airport Express
    'HOK' : 'Hong Kong',\
    'KOW' :'Kowloon',\
    'TSY' :'Tsing Yi',\
    'AIR' :'Airport',\
    'AWE' :'AsiaWorld Expo'}

sta_TCL = {\
    # TCL Tung Chung Line
    'HOK' : 'Hong Kong',\
    'KOW' : 'Kowloon',\
    'OLY' : 'Olympic',\
    'NAC' : 'Nam Cheong',\
    'LAK' : 'Lai King',\
    'TSY' : 'Tsing Yi',\
    'SUN' : 'Sunny Bay',\
    'TUC' : 'Tung Chung'}

sta_TML = {\
    # TML Tuen Ma Line
    'WKS' : 'Wu Kai Sha',\
    'MOS' : 'Ma On Shan',\
    'HEO' : 'Heng On',\
    'TSH' : 'Tai Shui Hang',\
    'SHM' : 'Shek Mun',\
    'CIO' : 'City One',\
    'STW' : 'Sha Tin Wai',\
    'CKT' : 'Che Kung Temple',\
    'TAW' : 'Tai Wai',\
    'HIK' : 'Hin Keng',\
    'DIH' : 'Diamond Hill',\
    'KAT' : 'Kai Tak',\
    'SUW' : 'Sung Wong Toi',\
    'TKW' : 'To Kwa Wan',\
    'HOM' : 'Ho Man Tin',\
    'HUH' : 'Hung Hom',\
    'ETS' : 'East Tsim Sha Tsui',\
    'AUS' : 'Austin',\
    'NAC' : 'Nam Cheong',\
    'MEF' : 'Mei Foo',\
    'TWW' : 'Tsuen Wan West',\
    'KSR' : 'Kam Sheung Road',\
    'YUL' : 'Yuen Long',\
    'LOP' : 'Long Ping',\
    'TIS' : 'Tin Shui Wai',\
    'SIH' : 'Siu Hong',\
    'TUM' : 'Tuen Mun'}

sta_TKL = {\
    # TKL Tseung Kwan O Line                    # Down
    'NOP' : 'North Point',\
    'QUB' : 'Quarry Bay',\
    'YAT' : 'Yau Tong',\
    'TIK' : 'Tiu Keng Leng',\
    'TKO' : 'Tseung Kwan O',\
    'LHP' : 'LOHAS Park',\
    'HAH' : 'Hang Hau',\
    'POA' : 'Po Lam'}                           # Up

sta_EAL = {\
    # EAL East Rail Line                        # Down
    'ADM' : 'Admiralty',\
    'EXC' : 'Exhibition Centre',\
    'HUH' : 'Hung Hom',\
    'MKK' : 'Mong Kok East',\
    'KOT' : 'Kowloon Tong',\
    'TAW' : 'Tai Wai',\
    'SHT' : 'Sha Tin',\
    'FOT' : 'Fo Tan',\
    'RAC' : 'Racecourse',\
    'UNI' : 'University',\
    'TAP' : 'Tai Po Market',\
    'TWO' : 'Tai Wo',\
    'FAN' : 'Fanling',\
    'SHS' : 'Sheung Shui',\
    'LOW' : 'Lo Wu',\
    'LMC' : 'Lok Ma Chau'}                      # UP

list_line_key = []
list_line_val = []
for i, j in line.items():
    list_line_key.append(str(i))
    list_line_val.append(str(j))
#print(list_line_key)
#print(list_line_val)
list_AEL_key = []
list_AEL_val = []
for i, j in sta_AEL.items():
    list_AEL_key.append(str(i))
    list_AEL_val.append(str(j))
#print(list_AEL_key)
#print(list_AEL_val)
list_TCL_key = []
list_TCL_val = []
for i, j in sta_TCL.items():
    list_TCL_key.append(str(i))
    list_TCL_val.append(str(j))
#print(list_TCL_key)
#print(list_TCL_val)
list_TML_key = []
list_TML_val = []
for i, j in sta_TML.items():
    list_TML_key.append(str(i))
    list_TML_val.append(str(j))
#print(list_TML_key)
#print(list_TML_val)
list_TKL_key = []
list_TKL_val = []
for i, j in sta_TKL.items():
    list_TKL_key.append(str(i))
    list_TKL_val.append(str(j))
#print(list_TKL_key)
#print(list_TKL_val)
list_EAL_key = []
list_EAL_val = []
for i, j in sta_EAL.items():
    list_EAL_key.append(str(i))
    list_EAL_val.append(str(j))
#print(list_EAL_key)
#print(list_EAL_val)
list_sta_key = [list_AEL_key, list_TCL_key, list_TML_key, list_TKL_key, list_EAL_key]
list_sta_val = [list_AEL_val, list_TCL_val, list_TML_val, list_TKL_val, list_EAL_val]