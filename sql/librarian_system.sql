create table if not exists book 
(
	b_id int auto_increment comment '书本编号',
    isbn char(12) not null comment 'ISBN编号',
    inventory int not null comment '库存量',
    b_name char(50) not null comment '书名',
    author char(30) not null default '佚名'  comment '作者',
    shelf_life datetime comment '上架时间',
    price double not null comment '价格',
    category char(30) default '综合' comment '类目',
    press char(30) not null comment '出版社',
    loan_status char(10) default 'NotOnLean' comment '借出状态',
    primary key(b_id)
) engine = InnoDB default charset=utf8mb4;

create table if not exists admin (
	a_name char(5) not null default 'root' comment '用户名',
    a_password char(20) not null comment '密码'
) engine = InnoDB default charset=utf8mb4;

create table if not exists user (
	u_id int auto_increment comment '用户ID',
    u_name char(20) not null comment '姓名',
    u_sex char(10) default 'male' not null comment '性别',
    u_password char(20) not null comment '密码',
    u_mail char(30) not null comment '邮箱',
    primary key(u_id)
) engine = InnoDB default charset = utf8mb4;

create table if not exists librarian(
	l_id int auto_increment comment '图书管理员ID',
    l_name char(20) not null comment '姓名',
    l_mail char(30) not null comment '邮箱',
    l_password char(20) not null comment '密码',
    primary key(l_id)
) engine = InnoDB default charset = utf8mb4;

create table if not exists announcement (
	a_id int auto_increment comment '公告ID',
    a_time datetime not null comment '公告时间',
    a_p_id int not null comment '公告发布者ID',
    content char(250) comment '公告内容',
    foreign key(a_p_id) references librarian(l_id),
    primary key(a_id)
) engine = InnoDB default charset = utf8mb4;

create table if not exists borrow_books (
    bb_id int  auto_increment comment '借书ID',
    bb_isbn char(50) not null  comment  '借的书的isbn号',
    bb_name char(20) not null comment '借书人的名称',
    bb_book_name char(50) not null  comment '借的书的书名',
    bb_start_time date not null  comment '借书起始时间',
    bb_deadline date not null comment '还书期限',
    bb_renew_count tinyint not null  default 0 comment '续借次数',
    bb_status int not null default 0 comment '处理状态',
    primary key(bb_id)
) engine = InnoDB default charset = utf8mb4;

insert into admin 
(a_name, a_password)
values
('root', '123456');

insert into user
(u_name, u_sex, u_password, u_mail)
values
('张三', 'male', 'zhangsan', 'zhangsan@qq.com'),
('李四', 'male', 'lisi', 'lisi@qq.com'),
('王五',  'female', 'wangwu', 'wangwu@qq.com');

insert into  librarian
(l_name, l_mail, l_password)
values
('李华', 'lihua@qq.com', 'lihua'),
('韩梅梅', 'hanmeimei@qq.com', 'hanmeimei');

insert into book 
(isbn, inventory, b_name, author, price, category, press, shelf_life)
values
('9787544291170', 8, '百年孤独', '加西亚·马尔克斯', 55.00, 'Literature', '南海出版社', '2017-08-01'),
('9787544297059', 8, '霍乱时期的爱情', '加西亚·马尔克斯', 69.00, 'Literature', '南海出版社', '2020-03-01'),
('9787111544937', 2, '深入理解计算机系统', '兰德尔 E.布莱恩特', 139.00, 'IndustrialTechnology', '机械工业出版社', '2016-12-01'),
('9787559602152', 10, '明朝那些事增补版', '当年明月', 405.00, 'HistoryAndGeography', '北京联合出版公司', '2021-09-01'),
('9787100090131', 6, '论法的精神（上下卷）', '孟德斯鸠', 160.00, 'PoliticalAndLaw', '商务印书馆', '2012-05-01'),
('9787103008331', 6, '肖邦夜曲集', '帕德雷夫斯基', 39.00, 'Art', '人民音乐出版社', '2017-03-01');