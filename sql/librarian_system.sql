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
