#ifndef TWORZ_KOD_CPP
#define TWORZ_KOD_CPP

#include "Tworz.h"

using namespace std;


Tworz::Tworz(Wprowadzone* w) : w(w), d(w->getTab_wymiar()) {}


ofstream& Tworz::getZapis(string s) {

	ofstream* f= new ofstream(s.c_str());
	
	if (!f->is_open()) {
		cout << "\nerror: Plik do zapisu nie został ostwatry:" << s  << endl;
		exit(1);
	} else {		
	}	
	return *f;
}



void Tworz::download() {
  cout << "download" << endl;
  string fact_name = w->getFact()->getName_tab();

  // download(w->getFact()->getWeb_site(), fact_name );

  //  pgloader(fact_name);
  //cout <<  w->getFact()->getName_tab() << endl;
  //w->getFact()->pokazTab(cout);

cout << "koniec donload "<< endl;
}



void Tworz::script(string address, string dane_do_pgloadera) {

    string file_address= create_file_address(f_script,  "" ,dane_do_pgloadera ,r_sh);
    ofstream& out= getZapis(file_address);
    string p="";
   if ( address.rfind("/") != string::npos) {
     p = address.substr(address.rfind("/")+1);
   }

string p_md5="md5file_"+dane_do_pgloadera+".md5";

out << "if [ ! -f " << p  << " ]  " << endl; 
out << "then " << endl; 
out << "	touch  " <<  p << endl; 
out << "	md5sum  " << p << " > " << p_md5 << endl; 
out << "fi " << endl; 
out << " " << endl; 
out << "if [ ! -f " << p_md5 <<" ]  " << endl; 
out << "then " << endl; 
out << "	md5sum  " << p << " > " << p_md5 << endl; 
out << "fi " << endl; 
out << " " << endl; 
out << "t=$(date '+%s') " << endl; 
out << "while [[ $(($(date '+%s') - $t)) -le 10800 ]]  " << endl; 
out << "do " << endl; 
out << "  wget -c " <<  address  << " -N 2>/dev/null " << endl; 
out << "  sleep 5s " << endl; 
out << "  md5sum -c  " << p_md5  << endl; 
out << "  wynik=$? " << endl; 
out << "  echo $wynik " << endl; 
out << "  if [  $wynik -eq 1 ] " << endl; 
out << "  then " << endl; 
out << "    echo \"----- Plik jest nowy  ---------\" " << endl; 
out << "    md5sum  " << p << " >  " << p_md5 << endl; 
out << "    tar -zcvf  ./arch/arch$(date '+%Y_%m_%d_%H%M%S').tar.gz "<< p << endl; 
out << "    cp  "<< p << "  dane_"<< dane_do_pgloadera <<".txt " << endl; 
out << "    break " << endl; 
out << "  fi " << endl; 
out << "done " << endl; 

out.close();
   message_file_create(file_address);
}


void Tworz::pgloader() {

}
void Tworz::pgloader(string tab ) {
	
		
         string file_address= create_file_address("pgloader_", "",tab,".conf");
	ofstream& out= getZapis(file_address);
	
out << "[pgsql]" << endl;
out << "base=dwh" << endl;
out << "host=localhost" << endl;
out << "user=etl" << endl;
out << "port=5432" << endl;
out << "pass=etl" << endl;
out << "log_mis_messages=INFO" << endl;
out << "client_min_messages=WARNING" << endl;
out << "pg_option_client_encoding='win-1250'" << endl;
out << "pg_option_standard_conforming_strings=on" << endl;
out << "pg_option_work_mem=128MB" << endl;
out << "copy_every=15000" << endl;
out << "empty_string=\"\\ \"" << endl;
out << "max_parallel_sections=4" << endl;
out << "null=NULL" << endl;
out << "["<< tab <<"]" << endl;
out << "table=intf_"<< tab   << endl;
out << "format=csv" << endl;
out << "datestyle=ymd" << endl;
out << "field_size_limit=512kB" << endl;
out << "field_sep=," << endl;
out << "quotechar=\"" << endl;
out << "columns=*" << endl;
out << "skip_header_lines=0" << endl;
out << "truncate=True" << endl;
out << "filename=dane_"+tab+".txt" << endl;
out << "reject_log=" << tab << ".reject_log" << endl;
out << "reject_data=" << tab <<".reject_data" << endl;

out.close();
	
   message_file_create(file_address);
}



void Tworz::message_file_create(string file) {
  cout << "Utworzono: " << file <<endl; 
}


string Tworz::g_create_table(string p, string tab) {
	return s_create_table+p+tab+"\n(";
}
string Tworz::g_drop_table(string p,string tab) {
  return s_drop_table+p+tab+";";
}

string Tworz::g_insert_into(string p, string tab) {
 return s_insert_into+ p + tab+ "\n(";
}

string Tworz::g_create_sequence(string tab) {
	string s="";
	
	s+= "drop sequence if exists "+tab+"_kmap_seq CASCADE;\n";
	s+= "create sequence " +  tab +"_kmap_seq \n";
	s+= "increment by 1\n";
	s+= "no minvalue\n";
	s+= "no maxvalue\n";
	s+= "start with 1\n";
    s+= "cache 1\n";
    s+= "cycle;\n";
	return s;
}
string Tworz::create_file_address(string prefix_file, string prefix_tab,  string tab, string type ) {
 return "./"+w->getSave_dir()+"/"+prefix_file + prefix_tab + tab + type;
}


void Tworz::create_table() {
//cout << "----------------------------- Tworzy tabele ---------------------- " << endl;
   create_tab_intf(w->getFact());  
   create_tab_stg(w->getFact());
   create_tab_promo(w->getFact());
   create_tab_fact(w->getFact());

   create_all_dimensions_tab(w->getFact());

//cout << "----------------------------- Tworzy tabele ---------------------- " << endl;
}

void Tworz::create_tab_intf(Tabela* tab) {
   string name_tab = tab->getName_tab();
   string file_address= create_file_address(f_create, p_intf,name_tab,f_sql);
   ofstream& out= getZapis(file_address);

    out <<  g_drop_table(p_intf,name_tab) << endl;
    out <<  g_create_table(p_intf, name_tab) << endl;
    out <<  tab->show_tab();
    out <<  ");" << endl;
    out.close(); 
   message_file_create(file_address);
}

void Tworz::create_tab_stg(Tabela* tab) {
  
   string name_tab = tab->getName_tab();
   string file_address= create_file_address(f_create, p_stg,name_tab,f_sql);
   ofstream& out= getZapis(file_address);

    out <<  g_drop_table(p_stg,name_tab) << endl;
    out <<  g_create_table(p_stg, name_tab) << endl;
    out <<  tab->show_tab();
    out <<  ");" << endl;
    out.close(); 
   message_file_create(file_address);
}

void Tworz::create_tab_promo(Tabela* tab) {
  
   string name_tab = tab->getName_tab();
   string file_address= create_file_address(f_create, p_promo,name_tab,f_sql);
   ofstream& out= getZapis(file_address);

    out <<  g_drop_table(p_promo,name_tab) << endl;
    out <<  g_create_table(p_promo, name_tab) << endl;
    out <<  tab->show_tab(1);
    out <<  ");" << endl;
    out.close(); 
   message_file_create(file_address);
}


void Tworz::create_tab_fact(Tabela* tab) {
  
   string name_tab = tab->getName_tab();
   string file_address= create_file_address(f_create, "",name_tab,f_sql);
   ofstream& out= getZapis(file_address);

    out <<  g_drop_table("",name_tab) << endl;
    out <<  g_create_table("", name_tab) << endl;
    out <<  tab->show_tab(1);
    out <<  ");" << endl;
    out.close(); 
   message_file_create(file_address);
}

void Tworz::create_all_dimensions_tab(Tabela* t ) {
      Tabela* dimension= NULL;
      string name_dim;
      vector<Columna*>& vec_column= t->getTab();

     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
         if (2 == (*it)->getTyp() ) {
	                     name_dim= (*it)->getNameColumnaWymiar(); 
	      dimension= w->getWymiar( name_dim);
	        if (NULL==dimension) {
		     
		     string file_address= create_file_address(f_create, "",name_dim,f_sql);
		     ofstream& out= getZapis(file_address);
		     out << g_drop_table("",name_dim) << endl;
		     out << g_create_sequence(name_dim) << endl; 
                     out << g_create_table("",name_dim) << endl;
		     out << "id_" << name_dim << " integer default nextval('"<< name_dim << "_kmap_seq')" << endl;
                     out << ", " << (*it)->getName() << endl;        
		     out << ");" << endl;
		     out.close();
		     message_file_create(file_address); 
		} else {
		     create_dimension(dimension);
		}
         }
     }

}
void Tworz::create_dimension(Tabela* dimension) {
     create_tab_intf(dimension);
     create_tab_stg_dimension(dimension);
     create_tab_dimension(dimension);
}

/////////////////////////////////////////////////


void Tworz::create_tab_stg_dimension(Tabela* tab) {
  
   string name_tab = tab->getName_tab();
   string file_address= create_file_address(f_create, p_stg,name_tab,f_sql);
   ofstream& out= getZapis(file_address);

     out << g_drop_table(p_stg,name_tab) << endl;
     out << g_create_sequence(name_tab) << endl; 

    out <<  g_create_table(p_stg, name_tab) << endl;    
    out << "  id_" << name_tab << " integer default nextval('"<< name_tab << "_kmap_seq')" << endl;
    out << "," <<  tab->show_tab();
    out <<  ");" << endl;
    out.close(); 
   message_file_create(file_address);
}


void Tworz::create_tab_dimension(Tabela* tab) {
  
   string name_tab = tab->getName_tab();
   string file_address= create_file_address(f_create, "",name_tab,f_sql);
   ofstream& out= getZapis(file_address);

     out << g_drop_table("",name_tab) << endl;
    out <<  g_create_table("", name_tab) << endl;    
    out << "  id_" << name_tab << " integer " << endl;
    out << "," <<  tab->show_tab();
    out <<  ");" << endl;
    out.close(); 
   message_file_create(file_address);
}


////////////////////////////////////////////////////////////////////////////////////////////////////     Główna funkcja sterujące 
void Tworz::insert() {
//cout << "Tworzenie  procesów dotyczące warstwy pośredniej i docelowej " << endl; 

Tabela* dimension= NULL;
string name_dim;
vector<Columna*>& vec_column= w->getFact()->getTab();

insert_stg(w->getFact());

     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
         if (2 == (*it)->getTyp() ) {
                name_dim= (*it)->getNameColumnaWymiar(); 
     	        dimension= w->getWymiar( name_dim);

	        if (NULL==dimension) {
                     insert_kmap_dimension(w->getFact());
		} else {
		     insert_stg(dimension);
		}
         }
     }


insert_promo(w->getFact());


     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
         if (2 == (*it)->getTyp() ) {
                name_dim= (*it)->getNameColumnaWymiar(); 
     	        dimension= w->getWymiar( name_dim);

	        if (NULL==dimension) {
		} else {
		     insert_dimension(dimension);
		}
         }
     }


insert_fact(w->getFact());

//cout << "Koniec  Tworzenia procesów dotyczące warstwy pośredniej i docelowej \n\n\n" << endl; 
}



////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////      Warstwa Pośrednia i docelowa
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void Tworz::insert_stg(Tabela* t ) {
  string name_tab= t->getName_tab();
  vector<Columna*>& vec_column= t->getTab();
int count_key=0;
  string file_address= create_file_address( "", p_stg,name_tab,f_sql);
  ofstream& out= getZapis(file_address);

  out << g_insert_into(p_stg,name_tab) << endl;
 
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	if (it==vec_column.begin() ) {
		out << "  ";
	} else {
		out << ", ";
	}
	out << (*it)->getNameColumna()  << endl;
     }

  out << ")" << endl;
  out << s_select << endl; 

     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	if (it==vec_column.begin() ) {
		out << "  ";
	} else {
		out << ", ";
	}
	out << (*it)->getNameColumna()  << endl;
     }

  out << s_from << p_intf << name_tab << " i " << endl;
  out << s_where_not_exists << endl;
  out << "(" << endl;
  out << "    " << s_select << " 1 " << endl;
  out << "    " << s_from << p_stg << name_tab << " s " << endl;
  out << "    " << s_where << endl;
     count_key=0;
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
         if (0 != (*it)->getTyp() ) {
	     if (0==count_key) {
	        out << "        ";
	     } else { 
		out << "    and "; 
	     }
	     count_key++;
             out << "i." << (*it)->getNameColumna() << "= s."  << (*it)->getNameColumna()  << endl;
         }
      } 
  out << ");" << endl;

  out.close();
  message_file_create(file_address); 
}

void Tworz::insert_kmap_dimension(Tabela* t) {

      Tabela* dimension= NULL;
      string name_dim;
      vector<Columna*>& vec_column= t->getTab();

     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
         if (2 == (*it)->getTyp() ) {
	                     name_dim= (*it)->getNameColumnaWymiar(); 
	      dimension= w->getWymiar( name_dim);
	        if (NULL==dimension) {
		     
		     string file_address= create_file_address(p_kmap_from,t->getName_tab()+"_to_" ,name_dim,f_sql);
		     ofstream& out= getZapis(file_address);
                     out << g_insert_into("",name_dim) << endl;
			out << (*it)->getNameColumna() << endl;
		        out << ")" << endl;
                     out << s_select_distinct << endl;
		     out << (*it)->getNameColumna() << endl;
		     out << s_from << p_stg << t->getName_tab() <<  " s "  << endl;
                     out << s_where_not_exists  << endl;
 		     out << "(" << endl;
		     out << "    " << s_select << " 1 " << endl;
		     out << "    " << s_from << " " << name_dim  << " k " << endl;
		     out << "    " << s_where << " s." << (*it)->getNameColumna()  << " = k." << (*it)->getNameColumna()  << endl; 
		     out << ")" << endl;
		     out.close();
		     message_file_create(file_address); 
		} else {

		}
         }
     }

}
void Tworz::insert_promo(Tabela* t) {

  string name_tab= t->getName_tab();
  vector<Columna*>& vec_column= t->getTab();
int count_key=0;
  string file_address= create_file_address( "", p_promo,name_tab,f_sql);
  ofstream& out= getZapis(file_address);
 
  char alians='a'; 
  out << s_truncate_table << p_promo  << name_tab  << ";" << endl;
  out << g_insert_into(p_promo,name_tab) << endl;
 
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	if (it==vec_column.begin() ) {
		out << "  ";
	} else {
		out << ", ";
	} 
        if (2 == (*it)->getTyp()  )  {
	    out << "id_" << (*it)->getNameColumnaWymiar()  << endl;
	} else {
	    out << (*it)->getNameColumna()  << endl;
	}
     }

  out << ")" << endl;
  out << s_select << endl; 

     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	if (it==vec_column.begin() ) {
		out << "  ";
	} else {
		out << ", ";
	}
        if (2 == (*it)->getTyp()  )  {
	    out << alians++ <<  ".id_" << (*it)->getNameColumnaWymiar()  << endl;
	} else {
	    out << "s." <<  (*it)->getNameColumna()  << endl;
	}
     }

  out << s_from << p_stg << name_tab << " s " << endl;

   alians='a';
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
        if (2 == (*it)->getTyp()  )  {
        out << s_join  << (*it)->getNameColumnaWymiar() << " "  << alians    << " "  << s_on;
	    out << alians++ <<  "." <<  (*it)->getNameColumna() << " = s." << (*it)->getNameColumna()   << endl;
	}
     }
  out << ";" << endl;
  out.close();
  message_file_create(file_address); 
}


void Tworz::insert_fact(Tabela* t ) {
  string name_tab= t->getName_tab();
  vector<Columna*>& vec_column= t->getTab();
int count_key=0;
  string file_address= create_file_address( "", "" ,name_tab,f_sql);
  ofstream& out= getZapis(file_address);

  out << g_insert_into("" ,name_tab) << endl;
 
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	if (it==vec_column.begin() ) {
		out << "  ";
	} else {
		out << ", ";
	}
        if (2 == (*it)->getTyp()  )  {
	    out << "id_" << (*it)->getNameColumnaWymiar()  << endl;
	} else {
	    out << "" <<  (*it)->getNameColumna()  << endl;
	}

     }

  out << ")" << endl;
  out << s_select << endl; 

     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	if (it==vec_column.begin() ) {
		out << "  ";
	} else {
		out << ", ";
	}
        if (2 == (*it)->getTyp()  )  {
	    out << "id_" << (*it)->getNameColumnaWymiar()  << endl;
	} else {
	    out << "" <<  (*it)->getNameColumna()  << endl;
	}
     }

  out << s_from << p_promo << name_tab << " i " << endl;
  out << s_where_not_exists << endl;
  out << "(" << endl;
  out << "    " << s_select << " 1 " << endl;
  out << "    " << s_from << "" << name_tab << " s " << endl;
  out << "    " << s_where << endl;
     count_key=0;
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
         if (0 != (*it)->getTyp() ) {
	     if (0==count_key) {
	        out << "        ";
	     } else { 
		out << "    and "; 
	     }
	     count_key++;
             out << "i." << (*it)->getNameColumna() << "= s."  << (*it)->getNameColumna()  << endl;
         }
      } 
  out << ");" << endl;

  out.close();
  message_file_create(file_address); 
}



void Tworz::insert_dimension(Tabela* t ) {
  string name_tab= t->getName_tab();
  vector<Columna*>& vec_column= t->getTab();
int count_key=0;
  string file_address= create_file_address( "", "" ,name_tab,f_sql);
  ofstream& out= getZapis(file_address);

  out << g_insert_into("",name_tab) << endl;
 
         out <<  "id_" << t->getName_tab() <<endl;
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	 out  << ",  "<< (*it)->getNameColumna()  << endl;
     }

  out << ")" << endl;
  out << s_select << endl; 

         out <<  "id_" << t->getName_tab() <<endl;
     for (vector<Columna*>::iterator it=vec_column.begin(); it != vec_column.end(); ++it) {
	out << ", " << (*it)->getNameColumna()  << endl;
     }

  out << s_from << p_stg << name_tab << " i " << endl;
  out << s_where_not_exists << endl;
  out << "(" << endl;
  out << "    " << s_select << " 1 " << endl;
  out << "    " << s_from << name_tab << " s " << endl;
  out << "    " << s_where << endl;
             out << "       i.id_" << t->getName_tab() << "= s.id_"  << t->getName_tab()  << endl;
  out << ");" << endl;

  out.close();
  message_file_create(file_address); 
}


#endif
