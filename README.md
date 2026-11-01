# Mini-Study-Timer
A small and portable study timer for keeping track of the time you spend learning or working on projects!
<img width="1175" height="645" alt="PCBRender1" src="https://github.com/user-attachments/assets/e675178d-1ed7-4677-ae05-da628fd22f4f" />

## Introduction
This is a mini study timer meant to track the time that you have spent studying. Its features include:

- A 0.91" OLED display to display the timer
- Buttons to control start/stop/pause/reset
- Visual indicator LEDs
- Planned functionality with a rotary encoder to set time

## PCB
My aim with the PCB was to make it relatively compact so that you could easily fit it into a backpack or pocket. But at the same time I also wanted to make it easy to work with since I am quite inexperienced with soldering and assembly.

### Schematic
The schematic itself follows a pretty regular layout.

Here is the XIAO ESP32 C3 as the main microcontroller:
<img width="743" height="631" alt="ESP32" src="https://github.com/user-attachments/assets/14e8cf01-8888-40fd-a020-0590de04ba8f" /><br>

The battery will connect to the battery pads on the bottom of the Xiao (*see PCB*)<br><br>

Here is the 0.91" OLED:
<br><img width="564" height="629" alt="OLED" src="https://github.com/user-attachments/assets/d26135d1-b57c-4e9c-ba5f-04cc0a4a3ccc" /><br>

I have included some extra pullup resistors and decoupling capacitors as recommended by the guide.<br><br>

This is the rotary encoder:
<br><img width="422" height="630" alt="RotEnc" src="https://github.com/user-attachments/assets/218b0b56-1c50-4389-bddc-1441283a4ed9" /><br>

I have included a very basic filter to hopefully help with debouncing.<br><br>

Here are the rest of the components:
<img width="1001" height="631" alt="Passives" src="https://github.com/user-attachments/assets/7bdcca1b-e4d0-4231-91db-471a49374c38" /><br>

These are the basic switches, LEDs and extra I2C headers that I have included along with a JST-PH connector for the battery.<br><br>


### PCB
As I said before, I have tried compacting the PCB layout quite a bit:
<img width="908" height="493" alt="FullBoard" src="https://github.com/user-attachments/assets/c143498c-b0af-4271-a8ac-1b426c04c4c6" /><br>

But I have also tried to arrange the parts in a way that makes sense, with the buttons and encoder below the screen and with the power switch on the right.<br><br>

Here are those battery pads I was talking about within the footprint of the Xiao:
<br><img width="415" height="450" alt="XIAOFootprint" src="https://github.com/user-attachments/assets/09044c40-1b5b-489a-80c5-1dc8f2628c16" /><br>

To connect these pads to the PCB I will simply push a header pin through the hole from the other side and solder it that way.

## Code
At its core the code runs a basic timer with the buttons controlling its main functions.
Here is a table showing the controls and functions of the timer:

| Component | Function |
|---|---|
| SW1 (Left on PCB) | Starts/pauses timer |
| SW2 (Right on PCB) | Resets and stops the timer |
| Rotary Encoder (UNFINISHED FEATURE) | Sets a countdown timer |
| Red LED | Lights up when timer is stopped |
| Green LED | Lights up when timer is active |

Unfortunately I was unable to completely finish the code for the rotary encoder in time, so right now the device can only count up the minutes and hours you have spent working.

[Here](https://wokwi.com/projects/479273044321545217) is the simulation i've made on WokWi to test the current functions (Note: I have absolutely no idea why, but the green LED connected to D6 on the XIAO ESP32 C3 simply refuses to turn on)

## BOM
|Item                    |Qty|Supplier  |Cost/item|Total Cost|link                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
|------------------------|---|----------|---------|----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|XIAO ESP32 C3           |1  |AliExpress|$8.55    |$8.55     |[AliExpress](https://www.aliexpress.com/item/1005008791937363.html?spm=a2g0o.productlist.main.2.3fccf128mRG5wj&algo_pvid=f91a3f44-7054-4a6c-b5ca-71a791d5faf8&algo_exp_id=f91a3f44-7054-4a6c-b5ca-71a791d5faf8-1&pdp_ext_f=%7B%22order%22%3A%221602%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21NOK%2179.84%2111.94%21%21%218.33%211.25%21%400b5e1a3817935633084165522e0e0a%2112000052930246748%21sea%21NO%218463637778%21X%211%210%21n_tag%3A-29911%3Bd%3A22d43e35%3Bm03_new_user%3A-29895%3BpisId%3A5000000219877342&curPageLogUid=niJ9W14AGW5V&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008791937363%7C_p_origin_prod%3A)                                                                                                                 |
|0.91" OLED              |1  |AliExpress|$2.43    |$2.43     |[AliExpress](https://www.aliexpress.com/item/1005006823025817.html?spm=a2g0o.productlist.main.4.468b411fr6AAZN&algo_pvid=2569d209-d20a-4ce9-8cd6-a8dd480e45cc&aem_p4p_detail=20261101120438123246892630680005280555&algo_exp_id=2569d209-d20a-4ce9-8cd6-a8dd480e45cc-3&pdp_ext_f=%7B%22order%22%3A%22598%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21NOK%2122.67%2120.23%21%21%2115.69%2114.00%21%40210382de17935634779592233e10aa%2112000038417220460%21sea%21NO%218463637778%21X%211%210%21n_tag%3A-29911%3Bd%3A22d43e35%3Bm03_new_user%3A-29895%3BpisId%3A5000000220744683&curPageLogUid=QDjpxSoLt2EF&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006823025817%7C_p_origin_prod%3A&search_p4p_id=20261101120438123246892630680005280555_1)   |
|Rotary Encoder          |1  |AliExpress|$1.56    |$1.56     |[AliExpress](https://www.aliexpress.com/item/1005007644083514.html?spm=a2g0o.productlist.main.1.363968b6NvMQQN&algo_pvid=ecab3b09-9889-40fe-b5bb-468045627bf3&algo_exp_id=ecab3b09-9889-40fe-b5bb-468045627bf3-0&pdp_ext_f=%7B%22order%22%3A%224885%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21NOK%2114.57%2110.45%21%21%211.52%211.10%21%400b88ab6717935636427541071e0f7b%2112000041630839409%21sea%21NO%218463637778%21X%211%210%21n_tag%3A-29911%3Bd%3A22d43e35%3Bm03_new_user%3A-29895%3BpisId%3A5000000219877342&curPageLogUid=OE90QjaOwzU0&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007644083514%7C_p_origin_prod%3A)                                                                             |
|Passive Components      |1  |AliExpress|$8.92    |$8.92     |[Capacitors](https://www.aliexpress.com/item/1005011747293156.html?spm=a2g0o.productlist.main.4.71c07baeewHVSt&algo_pvid=53fa7523-91ab-4fc5-9a37-791a7be0863d&aem_p4p_detail=202611011216112607374392124900005273353&algo_exp_id=53fa7523-91ab-4fc5-9a37-791a7be0863d-3&pdp_ext_f=%7B%22order%22%3A%223213%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21NOK%2122.06%2118.62%21%21%2115.27%2112.89%21%4021613ab217935641713446056e0fa2%2112000056423315138%21sea%21NO%218463637778%21X%211%210%21n_tag%3A-29911%3Bd%3A22d43e35%3Bm03_new_user%3A-29895%3BpisId%3A5000000221000707&curPageLogUid=9U2JRaZ3bgVG&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005011747293156%7C_p_origin_prod%3A&search_p4p_id=202611011216112607374392124900005273353_3) [Resistors](https://www.aliexpress.com/item/1005002994755806.html?spm=a2g0o.cart.0.0.3f3a38dakuPmuS&mp=1&pdp_npi=6%40dis%21NOK%21NOK+29.90%21NOK+24.36%21%21NOK+24.36%21%21%21%400b8848e317935654396147496e0f29%2112000023122336560%21ct%21NO%218463637778%21%211%210%21)|
|JST-PH Connector        |1  |AliExpress|$1.67    |$1.67     |[AliExpress](https://www.aliexpress.com/item/1005004955655144.html?spm=a2g0o.productlist.main.33.673e3206X0j96K&algo_pvid=20e9831a-0538-42f5-89b6-7565b2dfc96a&algo_exp_id=20e9831a-0538-42f5-89b6-7565b2dfc96a-32&pdp_ext_f=%7B%22order%22%3A%223896%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21NOK%218.34%216.96%21%21%210.87%210.73%21%400b88ab8a17935646038367827e104c%2112000033370425480%21sea%21NO%218463637778%21X%211%210%21n_tag%3A-29911%3Bd%3A22d43e35%3Bm03_new_user%3A-29895%3BpisId%3A5000000220732436&curPageLogUid=yGrFZekc6acZ&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005004955655144%7C_p_origin_prod%3A)                                                                             |
|PCB                     |1  |JLCPCB    |$6.72    |$6.72     |[JLCPCB](https://cart.jlcpcb.com/quote?spm=jlcpcb.Public.2006&spm=Jlcpcb.Instantquote&spm=Jlcpcb.Instantquote&_t=1791669462672&_t=1793564789078&up_spm=Jlcpcb.Loginpage.1003&up_spm=Jlcpcb.Loginpage.1003)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|3.7V LiPo               |1  |AliExpress|$4.11    |$4.11     |[AliExpress](https://www.aliexpress.com/item/1005010132479554.html?spm=a2g0o.productlist.main.1.401e5072TdpAZM&algo_pvid=f599faf2-6e03-4dbc-bcfc-387a4df46eb1&algo_exp_id=f599faf2-6e03-4dbc-bcfc-387a4df46eb1-0&pdp_ext_f=%7B%22order%22%3A%221236%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21NOK%21217.91%2138.38%21%21%21150.81%2126.56%21%4021038b2f17935651508853358e0d64%2112000051255130084%21sea%21NO%218463637778%21X%211%210%21n_tag%3A-29911%3Bd%3A22d43e35%3Bm03_new_user%3A-29895%3BpisId%3A5000000219877342&curPageLogUid=Mbz1Z1oNIHlF&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010132479554%7C_p_origin_prod%3A)                                                                         |
|Estimated total shipping|1  |          |         |$5.86     |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |

- The prices listed here represent the **maximum possible** prices for each of the items, in reality, significant discounts do apply
- I am completely willing to cover all additional costs that are not coverered by the base 30$

Cart Screenshots (1kr ≈ $0.1):

Aliexpress order:
<img width="1200" height="829" alt="Cart1" src="https://github.com/user-attachments/assets/4e9af7fe-572b-4e53-a90c-3e0020837779" />

<img width="1191" height="911" alt="Cart2" src="https://github.com/user-attachments/assets/afd710ed-cf80-47e4-ad52-4ea250b095d2" />
Total (discounts at time checked + shipping/tax): **$29.22** <br> <br>

JLCPCB order:
<img width="1415" height="538" alt="PCB Cart" src="https://github.com/user-attachments/assets/8bafaddf-85db-4977-9e63-3fd8e6a88601" />

Total (with discounts at time checked + shipping/tax): **$6.72**

Grand Total: **$35.94**




