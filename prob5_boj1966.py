if __name__ == '__main__':
    num = int(input())
    # 2 3 4 1 FIND 1 - 1 0
    for j in range(num):
        arr = []
        size, find = input().split()
        size = int(size)
        find = int(find)
        #print(size,find)
        t_f = 0 # 횟수 ->

        #--- 배열에 추가
        arr = [int(x) for x in input().split()]
        #-----

        while(1):
            #print("find",find) 2번3 - 3
            max=arr[0]
            for k in range(len(arr)):
                if arr[k] > max:
                    max = arr[k]
            if max != arr[0]: #더 큰 우선순위가 존재함
                tmp = arr[0]
                arr.remove(tmp)#앞에서 빼서
                arr.append(tmp)#뒤로가
                if find == 0:
                    find = len(arr)-1
                else:
                    find -=1
            else:
                t_f+=1
                if find == 0:
                    print(t_f)
                    break
                arr.remove(arr[0])
                find -=1
