
.open vcap.db
#create tables 
create table users(
userID int primary key not null,
username text not null,
password text not null
);

create table diseases(
diseaseID int primary key not null,
name text not null
);

create table diagnoses(
diagnoseID int primary key not null,
diagnoseDate date not null,
userID int not null,
diseaseID int not null,
foreign key (userID) references users(userID),
foreign key (diseaseID) references diseases(diseaseID)
);

#insert into users table
insert into users values(01,"nurse1","password1");
insert into users values(02,"nurse2","password2");
insert into users values(03,"nurse3","password3");
insert into users values(04,"nurse4","password4");
insert into users values(05,"nurse5","password5");

#insert into disease table
insert into diseases values(01,"Ebola");
insert into diseases values(02,"Flu");
insert into diseases values(03,"Cold");
insert into diseases values(04,"Anthrax");
insert into diseases values(05,"Malaria");
insert into diseases values(06,"Tuberculosis");
insert into diseases values(07,"Dengue");
insert into diseases values(08,"Hepatitis C");
insert into diseases values(09,"Hepatitis B");

#insert into diagnoses table
insert into diagnoses values(01,'2019-08-17',02,04);
insert into diagnoses values(02,'2019-10-01',01,01);
insert into diagnoses values(03,'2019-09-02',02,05);
insert into diagnoses values(04,'2019-08-01',03,06);
insert into diagnoses values(05,'2019-07-10',03,07);
insert into diagnoses values(06,'2019-10-12',04,01);
insert into diagnoses values(07,'2019-06-14',05,09);
insert into diagnoses values(08,'2019-05-27',01,07);
insert into diagnoses values(09,'2019-10-20',05,01);
insert into diagnoses values(10,'2019-10-05',03,01);
insert into diagnoses values(11,'2019-10-23',04,01);
insert into diagnoses values(12,'2019-09-13',04,03);
insert into diagnoses values(13,'2019-08-05',01,02);
insert into diagnoses values(14,'2019-09-08',02,08);
insert into diagnoses values(15,'2019-09-01',05,03);





