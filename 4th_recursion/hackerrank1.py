
def crack(password,login,op,i):
    print(''.join(op),op)
    if(''.join(op)==login):
        return True
    for x in range(i,len(password)):
        op.append(password[x])
        if (crack(password,login,op,i+1)):
            return True
    if not(len(op)==0):
        del op[-1]
    return False
print(crack(['abc','def','a'],'abcaa',[],0))    
