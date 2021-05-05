depth_reading1 = int(input())
depth_reading2 = int(input())
depth_reading3 = int(input())
depth_reading4 = int(input())

if depth_reading1 < depth_reading2 and depth_reading2 < depth_reading3 and depth_reading3 < depth_reading4:
    print("Fish Rising")
elif depth_reading1 > depth_reading2 and depth_reading2 > depth_reading3 and depth_reading3 > depth_reading4:
    print("Fish Diving")
elif depth_reading1 == depth_reading2 and depth_reading2 == depth_reading3 and depth_reading3 == depth_reading4:
    print("Fish At Constant Depth")
else:
    print("No Fish")