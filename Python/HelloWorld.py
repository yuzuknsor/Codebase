# 1. 创建favorite.languages字典并提取Sarah喜欢的语言
favorite_languages = {
    'Jen': 'python',
    'Sarah': 'c',
    'Edward': 'rust',
    'Phil': 'python'
}

sarah_favorite_language = favorite_languages['Sarah']
print(sarah_favorite_language)

# 2. 创建河流及其流经国家的字典
rivers = {
    'Nile': 'Egypt',
    'Amazon': 'Brazil',
    'Yangtze': 'China'
}

# 打印每条河流的消息
for river, country in rivers.items():
    print(f"{river}流经{country}。")

# 打印每条河流的名字
for river in rivers.keys():
    print(river)

# 打印每个国家的名字
for country in rivers.values():
    print(country)

# 3. 创建宠物字典列表并打印信息
pets = [
    {'type': 'dog', 'owner': 'John'},
    {'type': 'cat', 'owner': 'Alice'},
    {'type': 'bird', 'owner': 'Bob'}
]

for pet in pets:
    print(f"Type: {pet['type']}, Owner: {pet['owner']}")

# 4. 创建能被3整除的数的列表并打印
numbers = [num for num in range(3, 31) if num % 3 == 0]
for number in numbers:
    print(number)

def myFunc(a, b, *args, **kwargs):
    item = {}
    aa = a
    bb = b
    item['a'] = aa
    item['b'] = b
    for i, ele in enumerate(args):
        item[i] = ele
    for key, val in kwargs.items():
        item[key] = val
    return item

user_input = input("Please enter your arguments, separated by spaces: ")
user_args = user_input.split() #将用户输入的字符串分割成多个子字符串

temp = myFunc(*user_args, name = '123', color = 'black') #从命令行读取用户输入的参数，分为多个参数传给myFunc

print(temp)
