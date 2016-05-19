using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Reflection;
using System.Globalization;
using System.IO;
using System.IO.IsolatedStorage;
using System.Threading;
using System.Text;
using System.Xml;
using System.Collections.Generic;
using System.Data.SQLite;

namespace MultiLang
{
    public partial class SelectLanguage : Form
    {
        public SelectLanguage()
        {
            InitializeComponent();
          this.Disposed += new System.EventHandler ( this.SelectLanguage_Disposed );
        }

        //----------------------------------------------
        //Enums
        //----------------------------------------------
        public enum enumStartupMode
        {
            UseDefaultCulture = 0,
            UseSavedCulture = 1,
            ShowDialog = 2
        }

        private enum enumCultureMatch
        {
            None = 0,
            Language = 1,
            Neutral = 2,
            Region = 3
        }

        //----------------------------------------------
        //Member Variables
        //----------------------------------------------
        private enumStartupMode StartupMode;
        private CultureInfo SelectedCulture;

        // The array of supported cultures is updated automatically by Multi-Language for Visual Studio
        private static string[] SupportedCultures = { "en-US", "zh-CHS", "ko-KR" } ; //MLHIDE

        //----------------------------------------------
        //Public Methods
        //----------------------------------------------
        public void LoadSettingsAndShow()
        {
            LoadSettingsAndShow(false);
        }

        public void LoadSettingsAndShow(Boolean ForceShow)
        {
            LoadSettings();

            if (ForceShow || (StartupMode == enumStartupMode.ShowDialog))
            {
                this.ShowDialog();

                if (lstCultures.SelectedItem != null)
                {
                    SelectedCulture = (CultureInfo)lstCultures.SelectedItem;
                }

                SaveSettings();
            }

            if (StartupMode != enumStartupMode.UseDefaultCulture)
            {
                if (SelectedCulture != null)
                {
                    // Actually change the culture of the current thread.
                    Thread.CurrentThread.CurrentUICulture = SelectedCulture;

                    if (ForceShow)
                    {
#if true
                        // The code generated by VS.NET cannot be used to change the 
                        // language of an active form. Show a message to this effect.
                        MessageBox.Show(WFA_psychometric_chart.Properties.Resources.The_settings_have_been_saved +
                                        WFA_psychometric_chart.Properties.Resources.The_language_change_will_take_,
                                        WFA_psychometric_chart.Properties.Resources.Select_language,
                                        MessageBoxButtons.OK);
#else
            MLRuntime.MLRuntime.BroadcastLanguageChanged() ;
#endif
                    }
                }
            }
        }

        //----------------------------------------------
        //Private Methods
        //----------------------------------------------

        //
        // SaveSettings and LoadSettings use an XML file, saved in so called
        // Isolated Storage.
        //
        // I'm not convinced that this is really the best way or the best place
        // to store this information, but it's certainly a .NET way to do it.
        //
        private void LoadSettings()
        {
            // Set the defaults
            StartupMode = enumStartupMode.ShowDialog;
            SelectedCulture = Thread.CurrentThread.CurrentUICulture;

            // Create an IsolatedStorageFile object and get the store
            // for this application.
            IsolatedStorageFile isoStorage = IsolatedStorageFile.GetUserStoreForDomain();

            // Check whether the file exists
            if (isoStorage.GetFileNames("CultureSettings.xml").Length > 0) //MLHIDE
            {
                // Create isoStorage StreamReader.
                StreamReader stmReader = new StreamReader
                                             (new IsolatedStorageFileStream
                                                   ("CultureSettings.xml",
                                                    FileMode.Open,
                                                    isoStorage)); //MLHIDE

                XmlTextReader xmlReader = new XmlTextReader(stmReader);

                // Loop through the XML file until all Nodes have been read and processed.
                while (xmlReader.Read())
                {
                    switch (xmlReader.Name)
                    {
                        case "StartupMode":                                         //MLHIDE
                            StartupMode = (enumStartupMode)int.Parse(xmlReader.ReadString());
                            break;
                        case "Culture":                                             //MLHIDE
                            String CultName = xmlReader.ReadString();
                            CultureInfo CultInfo = new CultureInfo(CultName);
                            SelectedCulture = CultInfo;
                            break;
                    }
                }

                // Close the reader
                xmlReader.Close();
                stmReader.Close();

            }

            isoStorage.Close();

        }

        private void SaveSettings()
        {

            // Get an isolated store for user, domain, and assembly and put it into 
            // an IsolatedStorageFile object.
            IsolatedStorageFile isoStorage = IsolatedStorageFile.GetUserStoreForDomain();

            // Create isoStorage StreamWriter and assign it to an XmlTextWriter variable.
            IsolatedStorageFileStream stmWriter = new IsolatedStorageFileStream("CultureSettings.xml", FileMode.Create, isoStorage); //MLHIDE
            XmlTextWriter writer = new XmlTextWriter(stmWriter, Encoding.UTF8);

            writer.Formatting = Formatting.Indented;
            writer.WriteStartDocument();
            writer.WriteStartElement("CultureSettings");                     //MLHIDE
            writer.WriteStartElement("StartupMode");                         //MLHIDE
            writer.WriteString(((int)StartupMode).ToString());
            writer.WriteEndElement();
            writer.WriteStartElement("Culture");                             //MLHIDE
            writer.WriteString(SelectedCulture.Name);
            writer.WriteEndElement();
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();

            stmWriter.Close();
            isoStorage.Close();
        }

        private void SelectLanguage_Load(object sender, System.EventArgs e)
        {
            enumCultureMatch Match = enumCultureMatch.None;
            enumCultureMatch NewMatch = enumCultureMatch.None;

            // Version 1 detected which subdirectories are present.

            //      String AsmLocation             = Assembly.GetExecutingAssembly ( ).Location;
            //      String AsmPath                 = Path.GetDirectoryName ( AsmLocation );
            //      List<String> DirList           = new List<String> ( );
            //
            //      DirList.AddRange ( Directory.GetDirectories ( AsmPath, "??" ) );
            //      DirList.AddRange ( Directory.GetDirectories ( AsmPath, "??-??*" ) );
            //
            //      foreach ( String SubDirName in DirList )
            //      {
            //        try
            //        {
            //          String BaseName = Path.GetFileName ( SubDirName );
            //          CultureInfo Cult     = new CultureInfo ( BaseName );

            // Version 2 used the SupportedCultures array in MlString.h,
            // which is autoamatically updated by Multi-Language for Visual Studio
            //      foreach ( String IetfTag in ml.SupportedCultures )

            // Version 3 uses the SupportedCultures array in this file, 
            // which is autoamatically updated by Multi-Language for Visual Studio
            foreach (String IetfTag in SupportedCultures)
            {
                try
                {
                    CultureInfo Cult = new CultureInfo(IetfTag);

                    // Note: The property lstCultures.DisplayName is set to "NativeName" in order to
                    //       show language name in its own language.
                    lstCultures.Items.Add(Cult);

                    // The rest of this logic is just to find the nearest match to the 
                    // current UI culture.
                    // How well does this culture match?    

                    //--lets print...
                 //   MessageBox.Show("Cult = " + Cult);
                        
                    if (SelectedCulture.Equals(Cult))
                    {
                        NewMatch = enumCultureMatch.Region;
                    }
                    else if (Cult.TwoLetterISOLanguageName == SelectedCulture.TwoLetterISOLanguageName)
                    {
                        if (Cult.IsNeutralCulture)
                            NewMatch = enumCultureMatch.Neutral;
                        else
                            NewMatch = enumCultureMatch.Language;
                    }

                    // Is that better than the best match so far?
                    if (NewMatch > Match)
                    {
                        Match = NewMatch;
                        lstCultures.SelectedItem = Cult;
                    }
                }
                catch
                {
                }
            }

            switch (StartupMode)
            {
                case enumStartupMode.ShowDialog:
                    rbShow.Checked = true;
                    break;
                case enumStartupMode.UseDefaultCulture:
                    rbDefault.Checked = true;
                    break;
                case enumStartupMode.UseSavedCulture:
                    rbSelected.Checked = true;
                    break;
            }

            //event should be button pressed
            btOK_Click(this, e);

        }


        //--This function returns the values of the ID based on the data present in database...
       public int DatabaseOperation()
        {
            int id_return = 1;
            string databasePath = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string databaseFile = databasePath + @"\db_psychrometric_project.s3db";

            string connString = @"Data Source=" + databaseFile + ";Version=3;";
            
            SQLiteConnection connection = new SQLiteConnection(connString);
            connection.Open();
            SQLiteDataReader reader = null;
            SQLiteCommand comm = new SQLiteCommand("SELECT * from tbl_language_option where language_id = 1", connection);
            //command.Parameters.AddWithValue("@1", userName)
            reader = comm.ExecuteReader();
            while (reader.Read())
            {

                //string selecte_location = reader["id"].ToString()+","+reader["country"].ToString() + "," + reader["state"].ToString() + "," + reader["city"].ToString();
                //stored_location.Add(selecte_location);
                id_return =int.Parse( reader["ID"].ToString());
     
            }
           //  MessageBox.Show("id ret = " + id_return);
            comm.Dispose();
            reader.Dispose();
            connection.Close();



            return id_return;
        }
        string lstCultureSelected;//= "en-US";
        private void btOK_Click(object sender, System.EventArgs e)
        {
            if (lstCultures.SelectedItem != null)
            {
                //--bbk This is changed based on the data available in the database..
                //Steps: 
                /*
                1.Connect to the databse.
                2. Get the id 
                3. if id=1 english,id=2 chinese and id = 3 then korean
                */
                //--Connect to database
                //"en-US", "zh-CHS", "ko-KR"

                int returnValueDB = DatabaseOperation();
                
                if (returnValueDB == 1)
                {
                    lstCultureSelected = "en-US";
                    // lstCultureSelected = "ko-KR";
                    lstCultures.SelectedIndex = 0;


                }
                else if(returnValueDB == 2)
                {
                    lstCultureSelected = "zh-CHS";
                    //lstCultures.SelectedIndex.Equals(2);
                    lstCultures.SelectedIndex = 1;
                }
                else
                {
                   // lstCultureSelected = "en-US";
                    lstCultureSelected = "ko-KR";
                    // lstCultures.SelectedIndex.Equals(1);
                    lstCultures.SelectedIndex = 2;
                }


               // lstCultures.Equals(lstCultureSelected);
               // lstCultures.SelectedItem.Equals(lstCultureSelected);
                SelectedCulture = (CultureInfo)lstCultures.SelectedItem;



                // MessageBox.Show("lstCultures.SelectedItem= "+ lstCultures.SelectedItem);//--bbk

            }
            this.Close();
        }

        private void OnStartup_CheckedChanged(object sender, System.EventArgs e)
        {
            if (rbShow.Checked)
                StartupMode = enumStartupMode.ShowDialog;
            else if (rbSelected.Checked)
                StartupMode = enumStartupMode.UseSavedCulture;
            else if (rbDefault.Checked)
                StartupMode = enumStartupMode.UseDefaultCulture;
        }


      public void SelectLanguage_Disposed ( object sender, System.EventArgs e )
      {
      }

       
    }
}