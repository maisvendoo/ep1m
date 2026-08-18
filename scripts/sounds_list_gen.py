import os

xml_file = open("sounds_list.xml", "w")
cpp_file = open("consts.cpp", "w")

SignalID = 314

v = 4

while v <= 138:
    
    name = 'ted_' + str(v) + '-' + str(v+2) + '.wav'
    
    print(name) 
    
    xml_file.write('\t<Sound>\n')
    xml_file.write('\t\t<SignalID>' + str(SignalID) + '</SignalID>\n')
    xml_file.write('\t\t<Filename>' + 'TED/' + name + '</Filename>\n')
    xml_file.write('\t\t<InitVolume>1.0</InitVolume>\n')
    xml_file.write('\t\t<MaxVolume>1.0</MaxVolume>\n')
    xml_file.write('\t\t<InitPitch>1.0</InitPitch>\n')  
    xml_file.write('\t\t<Loop>1</Loop>\n')
    xml_file.write('\t\t<PlayOnStart>0</PlayOnStart>\n')
    xml_file.write('\t\t<LocalPosition>-0.19 0.86 0.81</LocalPosition>\n')
    xml_file.write('\t</Sound>\n\n')
    
    tmp = 'SOUND_' + os.path.splitext(name)[0].upper().replace('-', '_')
    
    cpp_file.write(tmp + ' = ' + str(SignalID) + ',\n')
    
    
    SignalID = SignalID + 1
    v = v + 2
    
    

xml_file.close()
cpp_file.close()