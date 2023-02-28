const char *html_settings_header = 
"<!DOCTYPE html><html><head><title>HAA</title><style type=\"text/css\">"
"html,input,textarea{font-size:38px;font-family:Arial;}"
"h1{font-size:120%;text-align:center;margin:0;}"
"h2{font-size:75%;text-align:center;margin:0;}"
"body .container{width:22em;margin:0 auto;padding:0.5em;}"
"label{display:block;}"
"input[type=text],input[type=password]{width:100%;box-sizing:border-box;}"
"input[type=checkbox]{transform:scale(1.8);}"
"textarea{width:100%;box-sizing:border-box;height:5em;margin:2px auto;}"
"select{border:1px solid black;font-size:70%;text-decoration:none;padding:0.25em 0.25em;color:white;margin:0;background-color:#ac0000;cursor:pointer;-webkit-appearance:none;-webkit-border-radius:0;}"
"input[type=submit],input[type=button]{width: 100%;border:1px solid black;text-decoration:none;padding:0.25em 5em;color:white;background-color:#4caf50;cursor:pointer;-webkit-appearance:none;-webkit-border-radius:0;}"
"input[type=button]#refresh{background-color: #44bbe3;}"
"input[type=submit]#join{background-color: #4caf50;}"
"input[type=submit][disabled]{color:#aaaaaa;background-color:#eeeeee !important;}"
".networkheader{font-size:75%;font-weight:bold;margin:0.25em 0 0 0;padding:0;border-bottom:2px solid #aaa;text-align:center;}"
".networks{font-size:75%;list-style:none;margin:0.4em 0.4em;padding:0;}"
".networks li{cursor:pointer;padding:0.25em;margin-bottom:0.25em;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;position:relative;padding-left:1.1em;}"
".networks li.secure::before{content:\"🔒\";position:absolute;left:0;}"
".networks li.selected{font-weight:bold;background-color:#ddd}"
".networks li:hover{background-color:#eee;}"
".networks li.other{border-top:2px solid #aaa;text-align:center;}"
".nonetworks{text-align:center;margin:1em 0;}"
".field{margin-bottom:0.5em;}"
".field.required label::before{content:\"*\";color:red;}"
"</style></head><body><div class=\"container\"><h1>Home Accessory Architect<br>"HAA_FIRMWARE_VERSION""HAA_FIRMWARE_BETA_REVISION" "HAA_FIRMWARE_CODENAME"</h1>"
"<h2>(Installer ";

const char *html_settings_installer_version = 
")</h2>"
"<form action=\"/st\" method=\"post\">"
"<div class=\"field required\">"
"<label> MEPLHAA Script</label>"
"<textarea name=\"cnf\" autocorrect=\"off\" autocomplete=\"off\" autocapitalize=\"off\" spellcheck=\"false\">";

const char *html_settings_middle = 
"</textarea><br>";

const char *html_settings_pairings = 
"Pairings ";

const char *html_settings_pairings_count = 
"/48<br>";

const char *html_settings_add_extra_pairing = 
"<input type=\"checkbox\" name=\"rep\" value=\"y\"> Add Extra Pairing<br>";

const char *html_settings_remove_extra_pairing = 
"<input type=\"checkbox\" name=\"rmp\" value=\"y\"> Remove All Extra Pairings<br>";

const char *html_settings_reset_homekit_id = 
"<input type=\"checkbox\" name=\"rst\" value=\"y\"> Reset HomeKit ID<br>"
"<input type=\"checkbox\" name=\"rsy\" value=\"y\"> Reset Settings<br>"
"<input type=\"checkbox\" name=\"now\" value=\"y\"> Remove WiFi Settings<br>"
"<input type=\"checkbox\" name=\"ins\" value=\"y\"> Installer Setup<br>"
"<input type=\"checkbox\" name=\"ota\" value=\"y\"> Firmware Update<br>"
"<label> WiFi Mode <select name=\"wm\">"
"<option value=\"0\" ";

const char *html_wifi_mode_0 = 
">Normal</option>"
"<option value=\"1\" ";

const char *html_wifi_mode_1 = 
">Force BSSID</option>"
"<option value=\"2\" ";

const char *html_wifi_mode_2 = 
">Passive Roaming</option>"
"<option value=\"3\" ";

const char *html_wifi_mode_3 = 
">Active Roaming</option>"
"<option value=\"4\" ";

const char *html_wifi_mode_4 = 
">Roaming at boot</option>"
"</select></label>"
"<label> IR/RF Capture GPIO <select name=\"irx\">"
"<option value=\"-1\" selected>-</option>"
"<option value=\"0\">0</option>"
"<option value=\"2\">2</option>"
"<option value=\"3\">3</option>"
"<option value=\"4\">4</option>"
"<option value=\"5\">5</option>"
"<option value=\"12\">12</option>"
"<option value=\"13\">13</option>"
"<option value=\"14\">14</option>"
"<option value=\"15\">15</option>"
"<option value=\"16\">16</option>"
"</select></label></div>"
"<input type=\"submit\" id=\"join\" value=\"Save\" /><br><br>"
"<input type=\"button\" id=\"refresh\" value=\"⟲ Search WiFi\" onClick=\"window.location.reload(true)\"/>"
"<div class=\"nonetworks\" style=\"display:none;\">"
"None found"
"</div>"
"<label class=\"networkheader\">WiFi SSID (RSSI Channel) BSSID</label><ul id=\"networks\" class=\"networks\">";

const char *html_network_item = 
"<li class=\"%s\" id=\"%s\" title=\"%s\">%s (%s Ch%s) %s</li>";

const char *html_settings_footer = 
"<li class=\"other\">Enter WiFi manually</li>"
"</ul>"
"<div class=\"field bssid\" style=\"display:none;\">"
"<label for=\"bssid\">BSSID</label>"
"<input type=\"text\" id=\"bssid\" name=\"bid\" />"
"</div>"
"<div class=\"field required ssid\" style=\"display:none;\">"
"<label for=\"ssid\">SSID</label>"
"<input type=\"text\" id=\"ssid\" name=\"sid\" />"
"</div>"
"<div class=\"field required pass\" style=\"display:none;\">"
"<label for=\"pass\">Password</label>"
"<input type=\"password\" id=\"pass\" name=\"psw\" />"
"</div></form>"
"<center>© 2018-2023 Jos&eacute; A. Jim&eacute;nez Campos</center>"
"<h2>If you have paid for this firmware or for a device with it installed, you have been scammed. You must report the fraud to the authorities and claim the amount paid. <a href=\"https://raw.githubusercontent.com/RavenSystem/esp-homekit-devices/master/LICENSE\">LICENSE</a><h2>"
"</div><script>"
"var ssid_field,bssid_field,pass_block,pass_field,join_button;"
"networks_block=document.getElementById('networks');"
"ssid_block=document.querySelector('.field.ssid');"
"ssid_field=document.getElementById('ssid');"
"bssid_block=document.querySelector('.field.bssid');"
"bssid_field=document.getElementById('bssid');"
"pass_block=document.querySelector('.field.pass');"
"pass_field=document.getElementById('pass');"
"join_button=document.getElementById('join');"
"function enable(e){e.disabled='';}"
"function disable(e){e.disabled='disabled';}"
"function show(e){e.style.display='block';}"
"function hide(e){e.style.display='none';}"
"function selectNetwork(e){"
"let nets=document.querySelectorAll('ul.networks li');"
"for(var i=0;i<nets.length;i++){"
"nets[i].classList.remove('selected');"
"}"
"e.classList.add('selected');"
"}"
"var nets,i;"
"nets=document.querySelectorAll('ul.networks li.unsecure');"
"for(i=0;i<nets.length;i++){"
"nets[i].onclick=function(event){"
"event.preventDefault();"
"selectNetwork(this);"
"ssid_field.value=this.title;"
"bssid_field.value=this.id;"
"hide(ssid_block);"
"hide(bssid_block);"
"hide(pass_block);"
"disable(pass_field);"
"pass_field.value=\"\";"
"show(bssid_block);"
"enable(join_button);"
"}"
"}"
"nets=document.querySelectorAll('ul.networks li.secure');"
"for(i=0;i<nets.length;i++){"
"nets[i].onclick=function(event){"
"event.preventDefault();"
"selectNetwork(this);"
"ssid_field.value=this.title;"
"bssid_field.value=this.id;"
"hide(ssid_block);"
"hide(bssid_block);"
"enable(pass_field);"
"show(pass_block);"
"disable(join_button);"
"pass_block.classList.add('required');"
"}"
"}"
"nets=document.querySelectorAll('ul.networks li.other');"
"for(i=0;i<nets.length;i++){"
"nets[i].onclick=function(event){"
"event.preventDefault();"
"if(this.classList.contains('selected'))"
"return;"
"selectNetwork(this);"
"ssid_field.value=\"\";"
"bssid_field.value=\"\";"
"show(ssid_block);"
"show(bssid_block);"
"show(pass_block);"
"enable(ssid_field);"
"enable(bssid_field);"
"enable(pass_field);"
"disable(join_button);"
"pass_block.classList.remove('required');"
"}"
"}"
"if(document.querySelectorAll('ul.networks li').length==1)"
"show(document.querySelector('.nonetworks'));"
"let s=ssid_field;"
"let p=pass_field;"
"s.onchange=s.onkeydown=s.onpaste=s.oninput=p.onchange=p.onkeydown=p.onpaste=p.oninput=function(event){"
"var f=enable;"
"if(ssid_block.classList.contains('required')&&ssid_field.value=='')"
"f=disable;"
"if(pass_block.classList.contains('required')&&pass_field.value=='')"
"f=disable;"
"f(join_button);"
"}"
"</script></body></html>";