#!/bin/bash


add_record(){
	 read -p "Enter employee details as name, id and contact number : " name id contact
	 echo "Name : $name"
	 echo "Id : $id"
	 echo "Contact : $contact"
	 record_file_path=/home/kali/Desktop/employeeDetails.csv
       	 
	 if [  -e $record_file_path ] 
	 then 
		 grep -i "$id" employeeDetails.csv
		 if [ $? -eq 0 ]
		 then
		 	echo "Employee with same id number already exists. Id should be unique."
			echo -e "\n"
		 else 
			echo "$name,$id,$contact" >> employeeDetails.csv
	  	 	echo "Record added successfully"
	           	echo -e "\n"
		 fi
	 else 	 
		echo "$name,$id,$contact" >> employeeDetails.csv
	 	echo "Record added successfully"
	 	echo -e "\n"	
	fi
}

delete_record(){
	read -p "Enter id of record to be deleted : " delid
	grep -q "$delid" employeeDetails.csv
	if [ $? -ne  0 ]
	then
		echo "Given id does not exist in the file record."
	else
		sed -i "/$delid,/d" employeeDetails.csv
		echo -e "Deletion done successfully.\n"
	fi
	echo -e "\n"	
}

search_record(){
	read -p "Enter id of employee to search : " search_id
	grep -i "$search_id" employeeDetails.csv
	if [ $? -ne 0 ]
	then 
		echo -e "GIven user id does not exist.\n"
	fi
	echo -e "\n"	
}

display_allemp_details(){
	cat employeeDetails.csv
	echo -e "\n"
}

sort_records(){
	sort -t ',' -k2 -o "employeeDetails.csv" "employeeDetails.csv"
	echo "After sorting : "
	cat employeeDetails.csv
	echo -e "\n"
}

looper=0
while [ $looper -eq 0 ]
do 	
	echo "Select operation choice from the following : "
	echo "1. Create a record"
	echo "2. Delete emp record"
	echo "3. Search emp record"
	echo "4. Display emp details"
	echo "5. Sort records"
	echo "6. List all records"
	echo -e "7. Exit\n"
	read usr_choice
#echo $usr_choice


	case $usr_choice in
		1) add_record;;
		2) delete_record;;
		3) search_record;;
		4) search_record;;
		5) sort_records;;
		6) display_allemp_details;;
		7) looper=1;;
		*) echo "Did not enter appropriate choice."
	esac
done

