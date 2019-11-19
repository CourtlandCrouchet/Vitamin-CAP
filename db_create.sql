/*
 Author(s): Cameron Navero
 Updated: 11/14/2019
 Description: Function for calling and updating the database.
*/
.open vcap.db
create table users(
id integer primary key autoincrement,
username text not null,
password text not null
);

create table diseases(
id integer primary key autoincrement,
name text not null
);

create table diagnoses(
id integer primary key autoincrement,
diagnoseDate date not null,
userID int not null,
diseaseID int not null,
foreign key (userID) references users(id),
foreign key (diseaseID) references diseases(id)
);

insert into users values(null,"nurse1","password1");
insert into users values(null,"nurse2","password2");
insert into users values(null,"nurse3","password3");
insert into users values(null,"nurse4","password4");
insert into users values(null,"nurse5","password5");

insert into diseases values(null,"Ebola");
insert into diseases values(null,"Flu");
insert into diseases values(null,"Cold");
insert into diseases values(null,"Anthrax");
insert into diseases values(null,"Malaria");
insert into diseases values(null,"Tuberculosis");
insert into diseases values(null,"Dengue");
insert into diseases values(null,"Hepatitis C");
insert into diseases values(null,"Hepatitis B");

insert into diagnoses values(null,'2019-08-17',02,04);
insert into diagnoses values(null,'2019-10-01',01,01);
insert into diagnoses values(null,'2019-09-02',02,05);
insert into diagnoses values(null,'2019-08-01',03,06);
insert into diagnoses values(null,'2019-07-10',03,07);
insert into diagnoses values(null,'2019-10-12',04,01);
insert into diagnoses values(null,'2019-06-14',05,09);
insert into diagnoses values(null,'2019-05-27',01,07);
insert into diagnoses values(null,'2019-10-20',05,01);
insert into diagnoses values(null,'2019-10-05',03,01);
insert into diagnoses values(null,'2019-10-23',04,01);
insert into diagnoses values(null,'2019-09-13',04,03);
insert into diagnoses values(null,'2019-08-05',01,02);
insert into diagnoses values(null,'2019-09-08',02,08);
insert into diagnoses values(null,'2019-09-01',05,03);
insert into diagnoses values(null,'2019-11-13',05,01);
insert into diagnoses values(null,'2019-11-13',05,01);
insert into diagnoses values(null,'2019-11-13',05,01);
insert into diagnoses values(null,'2019-11-13',05,01);
