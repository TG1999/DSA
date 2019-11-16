def quicksort(arr,s,en):
    if(s>=en):
        return
    last_element=int(arr[en-1])
    secure_position=0
    i=0
    for elem in arr:
        if(int(elem)<last_element):
            arr[secure_position],arr[i]=arr[i],arr[secure_position]
            secure_position=secure_position+1
        i=i+1
    arr[secure_position],arr[en-1]=arr[en-1],arr[secure_position]
    quicksort(arr,s,secure_position-1)
    quicksort(arr,secure_position+1,en)
arr=[]
n=0
n=int(input())
arr=input().split(" ")
quicksort(arr,0,n)
print(arr)